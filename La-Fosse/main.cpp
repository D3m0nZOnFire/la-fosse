#include <iostream>
#include <windows.h>

#include "AppState.h"
#include "mainMenu.h"
#include "leaderboardMenu.h"
#include "OptionsMenu.h"
#include "BestiaryView.h"
#include "Game.h"
#include "Logger.h"
#include "terminal.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    hideCursor();

    AppState state = AppState::MainMenu;

    while (state != AppState::Quit) {
        switch (state)
        {
            case AppState::MainMenu: {
                state = runMainMenu();
                break;
            }
            case AppState::NewGame:
                logInfo("Entering new game");
                state = runGame();
                break;
            case AppState::GameOver:
                state = AppState::MainMenu;
                break;
            case AppState::Leaderboard:
                logInfo("Viewing leaderboard");
                displayLeaderboard();
                state = AppState::MainMenu;
                break;
            case AppState::Options:
                runOptionsMenu();
                state = AppState::MainMenu;
                break;
            case AppState::Bestiary:
                runBestiaryView();
                state = AppState::MainMenu;
                break;
        }
    }

    logInfo("Application exited cleanly");
    showCursor();
    std::cout << "\nFin de la partie. Votre score de prestige a ete sauvegarde." << std::endl;
    return 0;
}