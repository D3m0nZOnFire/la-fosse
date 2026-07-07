#include "leaderboardMenu.h"
#include "ScoreUtils.h"
#include "terminal.h"
#include "ansi.h"
#include "Menu.h"
#include <iostream>

static const int MAX_LEADERBOARD_ENTRIES = 10;

void displayLeaderboard() {
	const Menu menu = { "=== CLASSEMENT ===", { "Retour" }, 0 };
	int selection = 0;

	std::vector<ScoreEntry> scores = getScoreboard();

	while (true) {
		clearScreen();

		if (scores.empty()) {
			std::cout << "Aucun score enregistre.\n";
		}
		else {
			int count = (int)scores.size() < MAX_LEADERBOARD_ENTRIES ? (int)scores.size() : MAX_LEADERBOARD_ENTRIES;
			for (int i = 0; i < count; ++i)
			{
				std::cout << i + 1 << ".\t"
						  << scores[i].username << " - "
						  << scores[i].score << " pts\t"
						  << " (" << formatTimestamp(scores[i].timestamp) << ")\n";
			}
		}

		std::cout << "\n";
		drawMenu(menu, selection);

		MenuResult res = handleMenuInput(menu, selection);
		if (res == MenuResult::Select || res == MenuResult::Quit) break;
	}
}

static void printEntry(int rank, const ScoreEntry& entry, bool highlight) {
    if (highlight) std::cout << BOLD << FG_RED;
    std::cout << rank << ".\t"
        << entry.username << " - "
        << entry.score << " pts\t"
        << "(" << formatTimestamp(entry.timestamp) << ")\n";
    if (highlight) std::cout << RESET;
};

void displayPostGameLeaderboard(const ScoreEntry& playerEntry) {
    const Menu menu = { "=== RESULTAT ===", { "Retour" }, 0 };
    int selection = 0;

    std::vector<ScoreEntry> scores = getScoreboard();

    // find player's rank (1-based)
    int playerRank = (int)scores.size() + 1;
    for (int i = 0; i < (int)scores.size(); ++i) {
        if (scores[i].timestamp == playerEntry.timestamp &&
            scores[i].username == playerEntry.username) {
            playerRank = i + 1;
            break;
        }
    }

    while (true) {
        clearScreen();

        int count = (int)scores.size() < MAX_LEADERBOARD_ENTRIES ? (int)scores.size() : MAX_LEADERBOARD_ENTRIES;

        if (playerRank <= MAX_LEADERBOARD_ENTRIES) {
            // player is in top N — show top N, plus one extra if player is last
            for (int i = 0; i < count; ++i)
                printEntry(i + 1, scores[i], (i + 1) == playerRank);

            if (playerRank == MAX_LEADERBOARD_ENTRIES && playerRank < (int)scores.size())
                printEntry(playerRank + 1, scores[playerRank], false);
        }
        else {
            // player is outside top N — show top N, then context around player
            for (int i = 0; i < count; ++i)
                printEntry(i + 1, scores[i], false);

            if (playerRank > MAX_LEADERBOARD_ENTRIES + 1)
                std::cout << "...\n";

            int above = playerRank - 2; // index of entry above player
            int below = playerRank;     // index of entry below player

            if (above > count)         // guard: don't re-print top N entries
                printEntry(above + 1, scores[above], false);

            printEntry(playerRank, scores[playerRank - 1], true);

            if (below < (int)scores.size())
                printEntry(below + 1, scores[below], false);

            if (below + 1 < (int)scores.size())
                std::cout << "...\n";
        }

        std::cout << "\n";
        drawMenu(menu, selection);

        MenuResult res = handleMenuInput(menu, selection);
        if (res == MenuResult::Select || res == MenuResult::Quit) break;
    }
}