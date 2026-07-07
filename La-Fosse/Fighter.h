#pragma once

#include <vector>
#include <string>
#include <ostream>
#include "Beast.h"

class Fighter {
public:
    BeastInstance& beast;

    explicit Fighter(BeastInstance& b) : beast(b) {}
    virtual ~Fighter() = default;

    virtual std::string act(std::vector<BeastInstance>& allies, std::vector<BeastInstance>& opponents) = 0;

    bool isAlive() const { return beast.hp > 0; }

    friend std::ostream& operator<<(std::ostream& os, const Fighter& f) {
        os << f.beast.species->name << " [" << typeName(f.beast.species->type) << "]" << " HP " << f.beast.hp << "/" << f.beast.hpMax;
        return os;
    }
};

class PlayerFighter : public Fighter {
public:
    int targetIdx = 0;

    explicit PlayerFighter(BeastInstance& b) : Fighter(b) {}
    std::string act(std::vector<BeastInstance>& allies, std::vector<BeastInstance>& opponents) override;
};

class EnemyFighter : public Fighter {
public:
    explicit EnemyFighter(BeastInstance& b) : Fighter(b) {}
    std::string act(std::vector<BeastInstance>& allies, std::vector<BeastInstance>& opponents) override;
};
