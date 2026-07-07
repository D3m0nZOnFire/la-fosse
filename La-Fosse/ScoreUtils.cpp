#include "ScoreUtils.h"
#include "Logger.h"
#include "ansi.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>
#include <ctime>

static const std::string SCORES_FILE = "scores.csv";

std::vector<ScoreEntry> getScoreboard() {
	std::vector<ScoreEntry> scoreboard;
	std::vector<std::vector<std::string>> data = readCSV(SCORES_FILE);

	for (int i = 0; i < (int)data.size(); ++i) {
		const auto& row = data[i];
		if (row.size() < 3) continue;
		ScoreEntry entry;
		entry.timestamp = parseTimestamp(row[0]);
		try {
			entry.score = std::stoi(row[1]);
		}
		catch (...) {
			logError("getScoreboard: invalid score value in row " + std::to_string(i) + " - '" + row[1] + "'");
			continue;
		}
		entry.username = row[2];
		scoreboard.push_back(entry);
	}
	sortScoreboard(scoreboard);
	return scoreboard;
}

void addToScoreboard(const ScoreEntry& entry) {
	std::time_t now = entry.timestamp;

	std::ofstream file(SCORES_FILE, std::ios::app);
	if (!file.is_open()) {
		logError("addToScoreboard: failed to open scores.csv for writing");
		return;
	}
	file << now << "," << entry.score << "," << entry.username << "\n";
	file.close();
}

std::vector<std::vector<std::string>> readCSV(const std::string& filename) {
	std::vector<std::vector<std::string>> data;
	std::ifstream file(filename);

	if (!file.is_open()) {
		try {
			std::filesystem::path p(filename);
			if (p.has_parent_path()) {
				std::error_code ec;
				if (!std::filesystem::create_directories(p.parent_path(), ec) && ec) {
					logError("readCSV: failed to create directories for '" + filename + "' - " + ec.message());
					return data;
				}
			}

			std::ofstream outfile(filename, std::ios::app);
			if (!outfile) {
				logError("readCSV: failed to create file '" + filename + "'");
				return data;
			}
			outfile.close();

			file.open(filename);
			if (!file.is_open()) {
				logError("readCSV: file created but still can't open '" + filename + "'");
				return data;
			}
		}
		catch (const std::filesystem::filesystem_error& e) {
			logError(std::string("readCSV: filesystem_error - ") + e.what());
			return data;
		}
		catch (const std::exception& e) {
			logError(std::string("readCSV: unexpected exception - ") + e.what());
			return data;
		}
	}

	std::string line;
	while (std::getline(file, line)) {
		std::vector<std::string> row;

		std::stringstream ss(line);
		std::string cell;

		while (std::getline(ss, cell, ',')) {
			row.push_back(cell);
		}

		data.push_back(row);
	}

	file.close();
	return data;
}

std::time_t parseTimestamp(const std::string& s) {
	try {
		return static_cast<std::time_t>(std::stoll(s));
	}
	catch (...) {
		logError("parseTimestamp: invalid timestamp value '" + s + "'");
		return 0;
	}
}

std::string formatTimestamp(std::time_t timestamp) {
	std::tm timeinfo{};
	localtime_s(&timeinfo, &timestamp);
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M", &timeinfo);
	return std::string(buffer);
}

void swap(std::vector<ScoreEntry>& scoreboard, int i, int j) {
	if(i == j) return;
	ScoreEntry tmp = scoreboard[i];
	scoreboard[i] = scoreboard[j];
	scoreboard[j] = tmp;
}

void sortScoreboard(std::vector<ScoreEntry>& scoreboard) {
	bool sorted = false;
	for (int i = (int)scoreboard.size()-1; i > 0; --i)
	{
		sorted = true;
		for (int j = 0; j < i; j++)
		{
			if (scoreboard[j].score < scoreboard[j + 1].score) {
				sorted = false;
				swap(scoreboard, j, j+1);
			}
		}
		if(sorted) break;
	}
}
