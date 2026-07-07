#pragma once

#include <vector>
#include "Beast.h"
#include "Attack.h"

std::vector<BeastInstance*> getTurnOrder(std::vector<BeastInstance>& playerPack, std::vector<BeastInstance>& enemyPack);

int resolveAttack(const BeastInstance& attacker, const Attack& attack, BeastInstance& target);
bool isPackDefeated(const std::vector<BeastInstance>& pack);
void removeDeadBeasts(std::vector<BeastInstance>& pack);

struct CombatResult {
    bool won;
    std::vector<BeastInstance> survivors;
};

CombatResult runCombat(std::vector<BeastInstance>& playerPack, std::vector<BeastInstance>& enemyPack, int combatNumber = 0);

void applyPartialHeal(std::vector<BeastInstance>& pack);
void applyFullRest(std::vector<BeastInstance>& pack);
