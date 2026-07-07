#include "GameOverView.h"
#include "Menu.h"
#include "terminal.h"
#include "ansi.h"
#include <iostream>

void displayGameOver(const GameState& state) {
	const Menu menu = { "", { "Voir le classement" }, -1 };
	int selection = 0;

	while (true) {
		clearScreen();

		std::cout << FG_RED << BOLD;
		std::cout << "\n  ==============================\n";
		std::cout << "  ||      GAME  OVER           ||\n";
		std::cout << "  ==============================\n";
		std::cout << RESET << "\n";

		std::cout << "  Joueur   : " << FG_CYAN << state.playerName << RESET << "\n";
		std::cout << "  Combats  : " << FG_YELLOW << state.combatNumber << RESET << "\n";
		std::cout << "  Score    : " << FG_YELLOW << state.score << RESET << "\n\n";

		drawMenu(menu, selection);

		MenuResult res = handleMenuInput(menu, selection);
		if (res == MenuResult::Select) break;
	}
}
