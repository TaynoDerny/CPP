#include <iostream>
#include <fstream>
#include <string>

namespace Logger {

    enum LogLevel { INFO, WARNING, ERROR };

    void log(LogLevel level, const std::string& message) {
        switch (level) {
            case INFO:    std::cout << "[INFO] ";    break;
            case WARNING: std::cout << "[WARNING] "; break;
            case ERROR:   std::cout << "[ERROR] ";   break;
        }
        std::cout << message << "\n";
    }

    namespace FileLogger {

        void logToFile(const std::string& filename, const std::string& message) {
            std::ofstream file(filename, std::ios::app);
            if (file.is_open())
                file << message << "\n";
        }

    } // namespace FileLogger

} // namespace Logger

int main() {
    // using namespace Logger только внутри функции
    using namespace Logger;

    log(INFO,    "Application started");
    log(WARNING, "Low memory");
    log(ERROR,   "File not found");

    // Вложенный namespace — полная квалификация
    FileLogger::logToFile("app.log", "Logged to file");
    std::cout << "Message written to app.log\n";

    return 0;
}
