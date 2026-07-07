#include "BestiaryView.h"
#include "Bestiary.h"
#include "Type.h"
#include "Keys.h"
#include "ansi.h"
#include "terminal.h"
#include <iostream>
#include <string>

static constexpr int PAGE_SIZE = 10;

static void drawLore(const std::string& lore) {
    int lineLen = 0;
    std::cout << "  " << DIM;
    for (int i = 0; i < (int)lore.size(); ) {
        int wordEnd = i;
        while (wordEnd < (int)lore.size() && lore[wordEnd] != ' ') ++wordEnd;
        int wordLen = wordEnd - i;
        if (lineLen > 0 && lineLen + 1 + wordLen > 62) {
            std::cout << "\n  ";
            lineLen = 0;
        } else if (lineLen > 0) {
            std::cout << " ";
            ++lineLen;
        }
        std::cout.write(lore.c_str() + i, wordLen);
        lineLen += wordLen;
        i = wordEnd + 1;
    }
    std::cout << RESET << "\n";
}

static void drawBestiaryScreen(const std::vector<const Species*>& list, int selected) {
    clearScreen();

    int total = (int)list.size();
    int page = selected / PAGE_SIZE;
    int totalPages = (total + PAGE_SIZE - 1) / PAGE_SIZE;
    int pageStart = page * PAGE_SIZE;
    int pageEnd = std::min(pageStart + PAGE_SIZE, total);

    // Header
    std::cout << BOLD << "=== BESTIAIRE ===" << RESET
              << "  " << DIM << "Page " << (page + 1) << "/" << totalPages << RESET << "\n\n";

    // List
    for (int i = pageStart; i < pageEnd; ++i) {
        const Species* s = list[i];
        bool sel = (i == selected);

        if (sel) std::cout << BOLD << FG_BRIGHT_WHITE << " > ";
        else     std::cout << "   ";

        std::cout << s->name << RESET
                  << "  [" << typeColor(s->type) << typeName(s->type) << RESET << "]";

        if (sel) std::cout << RESET;
        std::cout << "\n";
    }

    // Detail panel
    const Species* s = list[selected];
    std::cout << "\n" << FG_BRIGHT_WHITE << BOLD
              << "────────────────────────────────────────\n" << RESET;
    std::cout << BOLD << FG_BRIGHT_WHITE << s->name << RESET
              << "  [" << typeColor(s->type) << typeName(s->type) << RESET << "]"
              << "  " << DIM << s->origin << RESET << "\n\n";
    std::cout << "  PV : " << s->hpBase
              << "   Vitesse : " << s->speedBase
              << "   Attaque : " << s->attackBase << "\n";
    std::cout << "  Capacité : " << s->attack->name << "\n\n";
    drawLore(std::string(s->lore));

    std::cout << "\n" << DIM
              << "(W/S ou ↑↓ naviguer   Echap quitter)" << RESET << "\n";
}

void runBestiaryView() {
    const auto& list = getBestiary();
    if (list.empty()) return;

    int selected = 0;
    int total = (int)list.size();

    while (true) {
        drawBestiaryScreen(list, selected);

        Keys k = ReadKey();
        if (k == Keys::Escape) return;
        if (k == Keys::W || k == Keys::ArrowUp)
            selected = (selected - 1 + total) % total;
        else if (k == Keys::S || k == Keys::ArrowDown)
            selected = (selected + 1) % total;
        else if (k == Keys::D || k == Keys::ArrowRight) {
            int nextPage = (selected / PAGE_SIZE + 1) % ((total + PAGE_SIZE - 1) / PAGE_SIZE);
            selected = nextPage * PAGE_SIZE;
        } else if (k == Keys::A || k == Keys::ArrowLeft) {
            int totalPages = (total + PAGE_SIZE - 1) / PAGE_SIZE;
            int prevPage = (selected / PAGE_SIZE - 1 + totalPages) % totalPages;
            selected = prevPage * PAGE_SIZE;
        }
    }
}
