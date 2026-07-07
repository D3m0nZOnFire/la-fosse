#pragma once

#include <stdexcept>
#include <string>

class CombatException : public std::runtime_error {
public:
    explicit CombatException(const std::string& msg) : std::runtime_error(msg) {}
};

class EmptyPackException : public CombatException {
public:
    explicit EmptyPackException(const std::string& side)
        : CombatException("Empty pack at combat start: " + side) {}
};
