#include "Game.h"
#include "GameState.h"
#include "PlayerSetup.h"
#include "EnemyGen.h"
#include "Combat.h"
#include "CombatView.h"
#include "CombatException.h"
#include "Recruitment.h"
#include "GameOverView.h"
#include "Scaling.h"
#include "AppState.h"
#include "Logger.h"
#include "leaderboardMenu.h"
#include "ScoreUtils.h"
#include "terminal.h"
#include "ansi.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <conio.h>

static ScoreEntry saveScore(const GameState& state) {
	ScoreEntry entry = {
		.timestamp = std::time(nullptr),
		.score = state.score,
		.username = state.playerName
	};
	addToScoreboard(entry);
	logInfo("Score saved — player: " + state.playerName + ", score: " + std::to_string(state.score));
	return entry;
}

static void handleGameOver(const GameState& state) {
	logInfo("Game over — player: " + state.playerName + ", combats: " + std::to_string(state.combatNumber) + ", score: " + std::to_string(state.score));
	displayGameOver(state);
	ScoreEntry entry = saveScore(state);
	displayPostGameLeaderboard(entry);
}

static void handleRecruitment(GameState& state, std::vector<BeastInstance>& enemies, int combatNumber) {
	if (enemies.empty()) return;

	int choice = recruitmentPhase(enemies);
	if (choice == -1) {
		logInfo("Player skipped recruitment");
		return;
	}

	if ((int)state.pack.size() >= 5) {
		int sacrifice = sacrificePhase(state.pack);
		logInfo("Player sacrificed: " + std::string(state.pack[sacrifice].species->name));
		state.pack.erase(state.pack.begin() + sacrifice);
	}

	BeastInstance recruited = applyCaptureBonus(enemies[choice].species, combatNumber);
	logInfo("Player recruited: " + std::string(recruited.species->name));
	state.pack.push_back(recruited);
}

AppState runGame() {
	std::srand((unsigned int)std::time(nullptr));

	GameState state;
	state.playerName = promptPlayerName();

	if (state.playerName.empty()) return AppState::MainMenu;

	logInfo("New game started — player: " + state.playerName);

	const Species* chosen = beastSelectionScreen();

	if (!chosen) return AppState::MainMenu;
	state.pack.push_back(applyCaptureBonus(chosen, 0));
	logInfo("Starting beast: " + std::string(chosen->name));

	while (true) {
		state.combatNumber++;
		logInfo("Combat #" + std::to_string(state.combatNumber) + " begins");

		std::vector<BeastInstance> enemies = generateEnemyPack(state.combatNumber, (int)state.pack.size());
		std::vector<BeastInstance> enemyRoster = enemies;
		int enemyCount = (int)enemies.size();

		CombatResult result;
		try {
			result = runCombat(state.pack, enemies, state.combatNumber);
		} catch (const EmptyPackException& e) {
			logError(std::string("EmptyPackException: ") + e.what());
			break;
		}

		if (!result.won) {
			handleGameOver(state);
			return AppState::MainMenu;
		}

		int kills = enemyCount;
		int survivors = (int)state.pack.size();
		int roundScore = 10 + kills * 2 + survivors;
		state.score += roundScore;
		logInfo("Round score: +" + std::to_string(roundScore) + " (10 base + " + std::to_string(kills) + " kills + " + std::to_string(survivors) + " survivors)");

		handleRecruitment(state, enemyRoster, state.combatNumber);

		if (state.combatNumber % 5 == 0) {
			applyFullRest(state.pack);
			logInfo("Full rest applied at combat #" + std::to_string(state.combatNumber));

			clearScreen();
			std::cout << "\n  " << FG_CYAN << BOLD << "Palier de repos !" << RESET << "  Toutes vos betes sont soignees.\n\n";
			std::cout << "  (Appuyez sur Entree...)\n";
			_getch();
		} else {
			applyPartialHeal(state.pack);
		}
	}

	return AppState::MainMenu;
}
