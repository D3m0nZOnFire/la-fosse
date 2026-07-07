#include "OptionsMenu.h"
#include "Options.h"
#include "Keys.h"
#include "ansi.h"
#include "terminal.h"
#include <iostream>
#include <string>
#include <vector>

struct OptionEntry {
    std::string label;
    bool* value;
};

static void drawOptionsMenu(const std::vector<OptionEntry>& entries, int selected) {
    clearScreen();
    std::cout << BOLD << "=== OPTIONS ===\n\n" << RESET;

    for (int i = 0; i < (int)entries.size(); ++i) {
        bool on = *entries[i].value;
        std::string badge = on
            ? std::string(FG_GREEN) + "[ON] " + RESET
            : std::string(FG_RED)   + "[OFF]" + RESET;

        if (i == selected)
            std::cout << BOLD << "> " << badge << " " << entries[i].label << RESET << "\n";
        else
            std::cout << "  " << badge << " " << entries[i].label << "\n";
    }

    std::cout << "\n" << DIM << "(W/S ou Fleches pour naviguer, Entree pour basculer, Echap/Q pour quitter)" << RESET << "\n";
}

void runOptionsMenu() {
    std::vector<OptionEntry> entries = {
        { "Aide de type  (Super efficace / Peu efficace)", &Options::get().showTypeHints },
    };

    int selected = 0;

    while (true) {
        drawOptionsMenu(entries, selected);

        Keys k = ReadKey();

        if (k == Keys::Escape) return;

        if (k == Keys::W || k == Keys::ArrowUp)
            selected = (selected - 1 + (int)entries.size()) % (int)entries.size();
        else if (k == Keys::S || k == Keys::ArrowDown)
            selected = (selected + 1) % (int)entries.size();
        else if (k == Keys::Enter)
            *entries[selected].value = !*entries[selected].value;
    }
}
