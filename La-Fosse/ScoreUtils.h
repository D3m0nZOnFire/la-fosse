#pragma once
#include <vector>
#include <string>
#include <ctime>

struct ScoreEntry {
	std::time_t timestamp;
	int score;
	std::string username;
};

std::vector<ScoreEntry> getScoreboard();
void addToScoreboard(const ScoreEntry& entry);
std::vector<std::vector<std::string>> readCSV(const std::string& filename);
std::time_t parseTimestamp(const std::string& s);
std::string formatTimestamp(std::time_t timestamp);
void sortScoreboard(std::vector<ScoreEntry>& scoreboard);