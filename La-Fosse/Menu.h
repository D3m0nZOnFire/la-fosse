#pragma once
#include "Keys.h"
#include <string>
#include <vector>

enum class MenuResult { None, Navigate, Select, Quit };

struct Menu {
    std::string title;
    std::vector<std::string> options;
    int quitIndex; // -1 if no quit option
};

MenuResult handleMenuInput(const Menu& menu, int& selection);
void drawMenu(const Menu& menu, int selection);
