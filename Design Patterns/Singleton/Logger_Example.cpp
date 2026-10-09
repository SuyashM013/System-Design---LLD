
#include <iostream>
using namespace std;

class Logger {
private:
    // Private constructor prevents external object creation
    Logger() {
        cout << "Logger created!" << endl;
    }

public:
    // Prevent copying
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    // Provides access to the single instance
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(string message) {
        cout << "[LOG]: " << message << endl;
    }
};

int main() {
    Logger& log1 = Logger::getInstance();
    Logger& log2 = Logger::getInstance();

    log1.log("Application started");
    log2.log("Employee logged in");

    cout << boolalpha;
    cout << (&log1 == &log2) << endl;

    return 0;
}