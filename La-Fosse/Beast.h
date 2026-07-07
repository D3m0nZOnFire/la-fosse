#pragma once

#include <string>
#include "Type.h"
#include "Attack.h"

struct Species {
    std::string name;
    Type type;
    int hpBase;
    int speedBase;
    int attackBase;
    const Attack* attack;
    std::string origin;
    std::string lore;
};

struct BeastInstance {
    const Species* species;
    int hpMax;
    int hp;
    int speed;
    int attack;
};
