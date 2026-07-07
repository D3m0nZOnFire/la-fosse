#include "CombatView.h"
#include "Menu.h"
#include "Options.h"
#include "Type.h"
#include "terminal.h"
#include "ansi.h"
#include <iostream>
#include <string>

static void drawHPBar(int current, int max, int width = 20) {
	int filled = (max > 0) ? (current * width / max) : 0;

	const char* color;
	float ratio = (max > 0) ? (float)current / max : 0.0f;
	if (ratio > 0.5f) color = FG_GREEN;
	else if (ratio > 0.25f) color = FG_YELLOW;
	else color = FG_RED;

	std::cout << color << "[";
	for (int i = 0; i < width; ++i)
		std::cout << (i < filled ? "#" : "-");
	std::cout << "]" << RESET;
	std::cout << " " << current << "/" << max;
}

static void drawBeastInstance(const BeastInstance& b, bool highlight) {
	if (highlight) std::cout << BOLD;
	std::cout << "  " << FG_BRIGHT_WHITE << b.species->name << RESET;
	std::cout << " [" << typeColor(b.species->type) << typeName(b.species->type) << RESET << "]  ";
	drawHPBar(b.hp, b.hpMax);
	if (highlight) std::cout << RESET;
	std::cout << "\n";
}

void drawCombatScreen(const std::vector<BeastInstance>& enemies, const std::vector<BeastInstance>& player, int combatNumber) {
	clearScreen();

	if (combatNumber > 0)
		std::cout << BOLD << FG_WHITE << "  Combat #" << combatNumber << "\n" << RESET;

	std::cout << FG_BRIGHT_RED << BOLD << "  ── Ennemis ─────────────────────────────\n" << RESET;
	for (const auto& b : enemies)
		drawBeastInstance(b, false);

	std::cout << "\n";
	std::cout << FG_BRIGHT_CYAN << BOLD << "  ── Votre meute ──────────────────────────\n" << RESET;
	for (const auto& b : player)
		drawBeastInstance(b, false);

	std::cout << "\n";
}

int pickTarget(const std::string& attackerName, const Attack* attackerAttack, const std::vector<BeastInstance>& targets, const std::vector<BeastInstance>& enemies, const std::vector<BeastInstance>& playerPack, int combatNumber) {
	std::vector<std::string> options;
	for (const auto& b : targets) {
		std::string badge;
		if (attackerAttack && Options::get().showTypeHints) {
			float m = typeMultiplier(attackerAttack->type, b.species->type);
			if (m > 1.0f)      badge = std::string("  ") + FG_YELLOW + "[✦ Très efficace]" + RESET;
			else if (m < 1.0f) badge = std::string("  ") + DIM       + "[↓ Peu efficace]"  + RESET;
			else               badge = std::string("  ") + FG_WHITE   + "[Neutre]"           + RESET;
		}
		options.push_back(
			std::string(b.species->name) +
			"  [" + typeName(b.species->type) + "]" +
			"  PV: " + std::to_string(b.hp) + "/" + std::to_string(b.hpMax) +
			badge
		);
	}

	const Menu menu = { attackerName + " — Choisir une cible", options, -1 };
	int selection = 0;

	while (true) {
		clearScreen();
		drawCombatScreen(enemies, playerPack, combatNumber);
		drawMenu(menu, selection);

		MenuResult res = handleMenuInput(menu, selection);
		if (res == MenuResult::Select)
			return selection;
	}
}

void printActionLog(const std::string& message) {
	std::cout << "  >> " << message << RESET << "\n";
}
