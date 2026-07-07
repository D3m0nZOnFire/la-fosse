#include "PlayerSetup.h"
#include "Bestiary.h"
#include "Type.h"
#include "Menu.h"
#include "Keys.h"
#include "terminal.h"
#include "ansi.h"
#include <iostream>

static const int PAGE_SIZE = 8;

std::string promptPlayerName() {
	clearScreen();
	showCursor();

	std::cout << "\n";
	std::cout << "  ================================\n";
	std::cout << "  ||    ENTREZ VOTRE NOM         ||\n";
	std::cout << "  ================================\n";
	std::cout << "  " << DIM << "(Echap pour annuler)" << RESET << "\n\n  > ";

	std::string name;
	while (true) {
		int ch = ReadChar();

		if (ch == KeyCode::ENTER) {
			if (!name.empty()) break;
		}
		else if (ch == KeyCode::ESCAPE) {
			hideCursor();
			return "";
		}
		else if (ch == KeyCode::BACKSPACE) {
			if (!name.empty()) {
				name.pop_back();
				std::cout << "\b \b";
			}
		}
		else if (ch >= 32 && ch <= 126 && (int)name.size() < 16) {
			name += static_cast<char>(ch);
			std::cout << static_cast<char>(ch);
		}
	}

	hideCursor();
	return name;
}

static void drawBeastPanel(const Species* s) {
	std::cout << "\n";
	std::cout << "  " << typeColor(s->type) << BOLD << s->name << RESET;
	std::cout << "  [" << typeColor(s->type) << typeName(s->type) << RESET << "]\n";
	std::cout << "  PV: " << s->hpBase << "   Vitesse: " << s->speedBase << "   Attaque: " << s->attackBase << "\n";
	std::cout << "\n  Attaque: " << s->attack->name << "  [" << typeColor(s->attack->type) << typeName(s->attack->type) << RESET << "]\n";
	std::cout << "\n";
}

const Species* beastSelectionScreen() {
	const auto& bestiary = getStarterBestiary();
	int total = (int)bestiary.size();
	int totalPages = (total + PAGE_SIZE - 1) / PAGE_SIZE;

	int page = 0;
	int selection = 0;

	while (true) {
		clearScreen();

		int pageStart = page * PAGE_SIZE;
		int pageEnd = std::min(pageStart + PAGE_SIZE, total);
		int pageCount = pageEnd - pageStart;

		std::cout << BOLD << FG_CYAN << "=== CHOISISSEZ VOTRE BETE ===" << RESET;
		std::cout << "  (Page " << page + 1 << "/" << totalPages << ")\n\n";

		for (int i = 0; i < pageCount; ++i) {
			const Species* s = bestiary[pageStart + i];
			if (i == selection)
				std::cout << BOLD << FG_RED << "  > [ " << s->name << "  [" << typeName(s->type) << "] ] <" << RESET << "\n";
			else
				std::cout << "      " << s->name << "  [" << typeName(s->type) << "]\n";
		}

		drawBeastPanel(bestiary[pageStart + selection]);
		std::cout << "  W/S: naviguer   A/D: changer de page   Entree: confirmer   " << DIM << "Echap: retour" << RESET << "\n";

		Keys key = ReadKey();

		if (key == Keys::Escape)
			return nullptr;
		else if ((key == Keys::ArrowUp || key == Keys::W) && selection > 0)
			selection--;
		else if ((key == Keys::ArrowDown || key == Keys::S) && selection < pageCount - 1)
			selection++;
		else if ((key == Keys::ArrowLeft || key == Keys::A) && page > 0) {
			page--;
			selection = 0;
		}
		else if ((key == Keys::ArrowRight || key == Keys::D) && page < totalPages - 1) {
			page++;
			selection = 0;
		}
		else if (key == Keys::Enter)
			return bestiary[pageStart + selection];
	}
}
