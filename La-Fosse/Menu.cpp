#include "Menu.h"
#include "ansi.h"
#include "terminal.h"
#include <iostream>

MenuResult handleMenuInput(const Menu& menu, int& selection) {
    int menuSize = (int)menu.options.size();
    if (menuSize <= 0) return MenuResult::None;

    Keys key = ReadKey();

    switch (key)
    {
        case Keys::W:
        case Keys::ArrowUp:
            selection = (selection - 1 + menuSize) % menuSize;
            return MenuResult::Navigate;

        case Keys::S:
        case Keys::ArrowDown:
            selection = (selection + 1) % menuSize;
            return MenuResult::Navigate;

        case Keys::Enter:
            if (menu.quitIndex >= 0 && selection == menu.quitIndex)
                return MenuResult::Quit;
            return MenuResult::Select;

        default:
            return MenuResult::None;
    }
}

void drawMenu(const Menu& menu, int selection) {
    std::cout << BOLD << FG_CYAN << menu.title << RESET << "\n\n";
    for (int i = 0; i < (int)menu.options.size(); ++i) {
        if (i == selection)
            std::cout << BOLD << FG_RED << "  > [ " << menu.options[i] << " ] <" << RESET << "\n";
        else
            std::cout << "      " << menu.options[i] << "    \n";
    }
}