#include "mainMenu.h"
#include "terminal.h"
#include <iostream>

AppState runMainMenu() {
	const Menu menu = {
		"=== LA FOSSE ===",
		{ "Nouvelle Partie", "Classement", "Bestiaire", "Options", "Quitter" },
		4
	};
    int selection = 0;

    while (true) {
        clearScreen();
        drawMenu(menu, selection);
        std::cout << "\n(Utilisez W/S ou Fleches, puis Entree)\n";

        MenuResult res = handleMenuInput(menu, selection);

        if (res == MenuResult::Quit)        return AppState::Quit;
        if (res == MenuResult::Select) {
            if (selection == 0) return AppState::NewGame;
            if (selection == 1) return AppState::Leaderboard;
            if (selection == 2) return AppState::Bestiary;
            if (selection == 3) return AppState::Options;
        }
    }
}