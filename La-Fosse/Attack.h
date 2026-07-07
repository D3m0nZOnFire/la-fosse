#pragma once

#include <string>
#include "Type.h"

struct Attack {
    std::string name;
    Type type;
    int baseDamage;
};