#include "EnemyGen.h"
#include "Bestiary.h"
#include "Scaling.h"
#include <algorithm>
#include <cstdlib>

static std::vector<int> shuffledIndices(int count) {
    std::vector<int> indices(count);
    for (int i = 0; i < count; ++i) indices[i] = i;
    for (int i = count - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(indices[i], indices[j]);
    }
    return indices;
}

std::vector<BeastInstance> generateEnemyPack(int combatNumber, int playerPackSize) {
    const auto& bestiary = getBestiary();

    int size = playerPackSize;
    auto indices = shuffledIndices((int)bestiary.size());

    std::vector<BeastInstance> pack;
    pack.reserve(size);
    for (int i = 0; i < size; ++i)
        pack.push_back(scaleEnemyBeast(bestiary[indices[i]], combatNumber));

    return pack;
}
