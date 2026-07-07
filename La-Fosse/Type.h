#pragma once

#include <string>

enum class Type {
    Fire,
    Water,
    Nature,
    Lightning,
    Shadow,
    Celestial,
    Earth,
    Wind
};

inline std::string typeName(Type t) {
    switch (t) {
        case Type::Fire: return "Feu";
        case Type::Water: return "Eau";
        case Type::Nature: return "Nature";
        case Type::Lightning: return "Foudre";
        case Type::Shadow: return "Ombre";
        case Type::Celestial: return "Céleste";
        case Type::Earth: return "Terre";
        case Type::Wind: return "Vent";
        default: return "?";
    }
}

// Returns the ANSI color code associated with a type for display.
inline const char* typeColor(Type t) {
    switch (t) {
        case Type::Fire: return "\033[91m"; // bright red
        case Type::Water: return "\033[94m"; // bright blue
        case Type::Nature: return "\033[92m"; // bright green
        case Type::Lightning: return "\033[93m"; // bright yellow
        case Type::Shadow: return "\033[35m"; // magenta
        case Type::Celestial: return "\033[97m"; // bright white
        case Type::Earth: return "\033[33m"; // yellow-brown
        case Type::Wind: return "\033[96m"; // bright cyan
        default: return "\033[0m";
    }
}

// 1.5 = advantage, 0.75 = weakness, 1.0 = neutral
inline float typeMultiplier(Type attackType, Type defenderType) {
    // Core triangle: Fire > Nature > Water > Fire
    if (attackType == Type::Fire && defenderType == Type::Nature) return 1.5f;
    if (attackType == Type::Nature && defenderType == Type::Water) return 1.5f;
    if (attackType == Type::Water && defenderType == Type::Fire) return 1.5f;

    if (attackType == Type::Nature && defenderType == Type::Fire) return 0.75f;
    if (attackType == Type::Water && defenderType == Type::Nature) return 0.75f;
    if (attackType == Type::Fire && defenderType == Type::Water) return 0.75f;

    // Lightning > Water
    if (attackType == Type::Lightning && defenderType == Type::Water) return 1.5f;
    if (attackType == Type::Water && defenderType == Type::Lightning) return 0.75f;

    // Shadow > Celestial
    if (attackType == Type::Shadow && defenderType == Type::Celestial) return 1.5f;
    if (attackType == Type::Celestial && defenderType == Type::Shadow) return 0.75f;

    // Earth > Lightning
    if (attackType == Type::Earth && defenderType == Type::Lightning) return 1.5f;
    if (attackType == Type::Lightning && defenderType == Type::Earth) return 0.75f;

    // Wind is neutral against everything
    return 1.0f;
}
