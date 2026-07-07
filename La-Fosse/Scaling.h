#pragma once

#include <cmath>
#include "Beast.h"

// k controls how fast enemy stats grow. At combat 10: x1.19, combat 50: x1.31, combat 100: x1.37.
static constexpr float SCALE_K = 0.08f;

// Capture bonus starts at +50% at combat 0 and decays toward 0%.
static constexpr float CAPTURE_BONUS = 0.50f;

inline BeastInstance scaleEnemyBeast(const Species* species, int combatNumber) {
    float multiplier = 1.0f + SCALE_K * std::log(static_cast<float>(combatNumber + 1));
    int scaledHp = static_cast<int>(species->hpBase * multiplier);
    return BeastInstance{
        .species = species,
        .hpMax = scaledHp,
        .hp = scaledHp,
        .speed = static_cast<int>(species->speedBase * multiplier),
        .attack = static_cast<int>(species->attackBase * multiplier),
    };
}

inline BeastInstance applyCaptureBonus(const Species* species, int combatNumber) {
    float bonus = CAPTURE_BONUS / (1.0f + std::log(static_cast<float>(combatNumber + 1)));
    float multiplier = 1.0f + bonus;
    int boostedHp = static_cast<int>(species->hpBase * multiplier);
    return BeastInstance{
        .species = species,
        .hpMax = boostedHp,
        .hp = boostedHp,
        .speed = static_cast<int>(species->speedBase * multiplier),
        .attack = static_cast<int>(species->attackBase * multiplier),
    };
}
