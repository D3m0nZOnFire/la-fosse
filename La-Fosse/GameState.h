#pragma once

#include <string>
#include <vector>
#include "Beast.h"

struct GameState {
    std::string playerName;
    std::vector<BeastInstance> pack;
    int combatNumber = 0;
    int score = 0;
};
