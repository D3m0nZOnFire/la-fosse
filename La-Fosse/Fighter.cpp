#include "Fighter.h"
#include "Combat.h"
#include "Logger.h"
#include "ansi.h"
#include <string>

std::string PlayerFighter::act(std::vector<BeastInstance>& allies, std::vector<BeastInstance>& opponents) {
    const Attack* attack = beast.species->attack;
    int idx = std::min(targetIdx, (int)opponents.size() - 1);

    if (opponents[idx].hp <= 0) {
        idx = -1;
        for (int i = 0; i < (int)opponents.size(); ++i) {
            if (opponents[i].hp > 0 && (idx == -1 || opponents[i].hp < opponents[idx].hp))
                idx = i;
        }
        if (idx == -1) return "";
    }

    BeastInstance& target = opponents[idx];

    int damage = resolveAttack(beast, *attack, target);

    std::string plain = std::string(beast.species->name) + "(P) utilise " + attack->name + " sur " + std::string(target.species->name) + " ! -" + std::to_string(damage) + " PV";
    logInfo(plain);

    return std::string(FG_BRIGHT_CYAN) + std::string(beast.species->name) + RESET + " utilise " + attack->name + " sur " + std::string(FG_BRIGHT_RED) + std::string(target.species->name) + RESET + " ! -" + std::to_string(damage) + " PV";
}

std::string EnemyFighter::act(std::vector<BeastInstance>& allies, std::vector<BeastInstance>& opponents) {
    BeastInstance* target = nullptr;
    for (auto& b : opponents)
        if (b.hp > 0 && (target == nullptr || b.hp < target->hp))
            target = &b;

    if (!target) return "";

    const Attack* attack = beast.species->attack;
    int damage = resolveAttack(beast, *attack, *target);

    std::string plain = std::string(beast.species->name) + " utilise " + attack->name + " sur " + std::string(target->species->name) + "(P) ! -" + std::to_string(damage) + " PV";
    logInfo(plain);

    return std::string(FG_BRIGHT_RED) + std::string(beast.species->name) + RESET + " utilise " + attack->name + " sur " + std::string(FG_BRIGHT_CYAN) + std::string(target->species->name) + RESET + " ! -" + std::to_string(damage) + " PV";
}
