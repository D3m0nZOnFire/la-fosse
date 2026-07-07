#pragma once

#include <vector>
#include "Beast.h"
#include "Attack.h"

void drawCombatScreen(const std::vector<BeastInstance>& enemies, const std::vector<BeastInstance>& player, int combatNumber = 0);
int pickTarget(const std::string& attackerName, const Attack* attackerAttack, const std::vector<BeastInstance>& targets, const std::vector<BeastInstance>& enemies, const std::vector<BeastInstance>& playerPack, int combatNumber = 0);
void printActionLog(const std::string& message);
