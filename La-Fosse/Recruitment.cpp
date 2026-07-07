#include "Recruitment.h"
#include "Menu.h"
#include "Type.h"
#include "terminal.h"
#include "ansi.h"
#include <iostream>
#include <string>

static std::string beastSummary(const BeastInstance& b) {
	return std::string(b.species->name)
		+ "  [" + typeName(b.species->type) + "]"
		+ "  PV: " + std::to_string(b.species->hpBase)
		+ "  Vit: " + std::to_string(b.species->speedBase)
		+ "  Atk: " + std::to_string(b.species->attackBase)
		+ "  >> " + b.species->attack->name;
}

int recruitmentPhase(const std::vector<BeastInstance>& survivors) {
	std::vector<std::string> options;
	for (const auto& b : survivors)
		options.push_back(beastSummary(b));
	options.push_back("Passer");

	const Menu menu = { "=== RECRUTEMENT — Choisissez une bete a capturer ===", options, (int)options.size() - 1 };
	int selection = 0;

	while (true) {
		clearScreen();
		drawMenu(menu, selection);

		MenuResult res = handleMenuInput(menu, selection);
		if (res == MenuResult::Quit || (res == MenuResult::Select && selection == (int)options.size() - 1))
			return -1;
		if (res == MenuResult::Select)
			return selection;
	}
}

int sacrificePhase(const std::vector<BeastInstance>& pack) {
	std::vector<std::string> options;
	for (const auto& b : pack)
		options.push_back(beastSummary(b));

	const Menu menu = { "=== MEUTE PLEINE — Choisissez une bete a liberer ===", options, -1 };
	int selection = 0;

	while (true) {
		clearScreen();
		std::cout << FG_YELLOW << "  Votre meute est pleine (5/5). Vous devez liberer une bete avant de recruter.\n\n" << RESET;
		drawMenu(menu, selection);

		MenuResult res = handleMenuInput(menu, selection);
		if (res == MenuResult::Select)
			return selection;
	}
}
