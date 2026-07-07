#include "Combat.h"
#include "CombatView.h"
#include "CombatException.h"
#include "Fighter.h"
#include "Logger.h"
#include "Type.h"
#include <algorithm>
#include <conio.h>
#include <iostream>
#include <memory>
#include <string>
#include <cstdlib>

std::vector<BeastInstance*> getTurnOrder(std::vector<BeastInstance>& playerPack, std::vector<BeastInstance>& enemyPack) {
	std::vector<BeastInstance*> order;

	for (auto& b : playerPack) order.push_back(&b);
	for (auto& b : enemyPack) order.push_back(&b);

	std::sort(order.begin(), order.end(), [](const BeastInstance* a, const BeastInstance* b) {
		return a->speed > b->speed;
	});

	return order;
}

int resolveAttack(const BeastInstance& attacker, const Attack& attack, BeastInstance& target) {
	float multiplier = typeMultiplier(attack.type, target.species->type);
	int damage = static_cast<int>((attack.baseDamage + attacker.attack) * multiplier);
	target.hp = std::max(0, target.hp - damage);
	return damage;
}

bool isPackDefeated(const std::vector<BeastInstance>& pack) {
	for (const auto& b : pack)
		if (b.hp > 0) return false;
	return true;
}

void removeDeadBeasts(std::vector<BeastInstance>& pack) {
	std::vector<BeastInstance> alive;
	for (const auto& b : pack)
		if (b.hp > 0) alive.push_back(b);
	pack = alive;
}

void applyPartialHeal(std::vector<BeastInstance>& pack) {
	for (auto& b : pack)
		b.hp += (b.hpMax - b.hp) * 3 / 4;
}

void applyFullRest(std::vector<BeastInstance>& pack) {
	for (auto& b : pack)
		b.hp = b.hpMax;
}

CombatResult runCombat(std::vector<BeastInstance>& playerPack, std::vector<BeastInstance>& enemyPack, int combatNumber) {
	if (playerPack.empty()) throw EmptyPackException("player");
	if (enemyPack.empty()) throw EmptyPackException("enemy");

	logInfo("Combat started — player: " + std::to_string(playerPack.size()) + " beasts, enemy: " + std::to_string(enemyPack.size()) + " beasts");

	while (true) {
		drawCombatScreen(enemyPack, playerPack, combatNumber);

		if (isPackDefeated(enemyPack)) { logInfo("Player wins combat"); return { true, {} }; }
		if (isPackDefeated(playerPack)) { logInfo("Player loses combat"); return { false, {} }; }

		// Phase 1 — collect player intentions
		std::vector<std::unique_ptr<PlayerFighter>> playerFighters;
		for (auto& b : playerPack)
			if (b.hp > 0) playerFighters.push_back(std::make_unique<PlayerFighter>(b));

		for (auto& pf : playerFighters) {
			drawCombatScreen(enemyPack, playerPack, combatNumber);
			pf->targetIdx = pickTarget(std::string(pf->beast.species->name), pf->beast.species->attack, enemyPack, enemyPack, playerPack, combatNumber);
		}

		// Phase 2 — build full turn order and execute
		auto order = getTurnOrder(playerPack, enemyPack);
		std::vector<std::unique_ptr<Fighter>> fighters;

		for (BeastInstance* b : order) {
			bool isPlayer = false;
			for (auto& pf : playerFighters)
				if (pf && &pf->beast == b) { isPlayer = true; break; }

			if (isPlayer) {
				for (auto& pf : playerFighters) {
					if (pf && &pf->beast == b) {
						fighters.push_back(std::move(pf));
						break;
					}
				}
			} else {
				fighters.push_back(std::make_unique<EnemyFighter>(*b));
			}
		}

		std::vector<std::string> roundLog;

		for (auto& fighter : fighters) {
			if (!fighter) continue;
			if (fighter->beast.hp <= 0) continue;

			bool isPlayer = dynamic_cast<PlayerFighter*>(fighter.get()) != nullptr;
			std::vector<BeastInstance>& allies = isPlayer ? playerPack : enemyPack;
			std::vector<BeastInstance>& opponents = isPlayer ? enemyPack : playerPack;

			bool anyAlive = false;
			for (const auto& b : opponents) if (b.hp > 0) { anyAlive = true; break; }
			if (!anyAlive) break;

			std::string actionMsg = fighter->act(allies, opponents);

			if (!actionMsg.empty()) {
				roundLog.push_back(actionMsg);
				drawCombatScreen(enemyPack, playerPack, combatNumber);
				for (const auto& line : roundLog)
					printActionLog(line);
				std::cout << "\n  (Appuyez sur Entree...)\n";
				_getch();
			}
		}

		removeDeadBeasts(playerPack);
		removeDeadBeasts(enemyPack);

		if (enemyPack.empty()) { logInfo("Player wins combat"); return { true, {} }; }
		if (playerPack.empty()) { logInfo("Player loses combat"); return { false, {} }; }
	}
}
