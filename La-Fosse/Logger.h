#pragma once

#include <fstream>
#include <string>
#include <ctime>

enum class LogLevel { Info, Warning, Error };

class Logger {
public:
    static Logger& instance() {
        static Logger logger;
        return logger;
    }

    void write(LogLevel level, const std::string& message) {
        if (!_file.is_open()) return;
        _file << "[" << timestamp() << "] [" << levelLabel(level) << "] " << message << "\n";
        _file.flush();
    }

private:
    std::ofstream _file;

    Logger() {
        _file.open("lafosse.log", std::ios::app);
        write(LogLevel::Info, "=== Session started ===");
    }

    ~Logger() {
        write(LogLevel::Info, "=== Session ended ===");
    }

    static std::string timestamp() {
        std::time_t t = std::time(nullptr);
        char buf[20];
        struct tm tm_info;
        localtime_s(&tm_info, &t);
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tm_info);
        return buf;
    }

    static const char* levelLabel(LogLevel level) {
        switch (level) {
            case LogLevel::Info: return "INFO";
            case LogLevel::Warning: return "WARNING";
            case LogLevel::Error: return "ERROR";
        }
        return "INFO";
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

inline void logInfo(const std::string& msg) { Logger::instance().write(LogLevel::Info, msg); }
inline void logWarning(const std::string& msg) { Logger::instance().write(LogLevel::Warning, msg); }
inline void logError(const std::string& msg) { Logger::instance().write(LogLevel::Error, msg); }
