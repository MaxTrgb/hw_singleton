#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Logger {
public:
	// Static function to get the instance of the Logger
	static Logger& getInstance() {
		static Logger instance; // This ensures that there is only one instance created.
		return instance;
	}

	// Log an event and message
	void log(const string& message) {
		logEntries.push_back(message);
	}

	// Get the log entries
	vector<string> getLogs() const {
		return logEntries;
	}

private:
	// Private constructor to prevent instantiation
	Logger() {}

	// Private copy constructor and assignment operator to prevent copying
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;

	vector<string> logEntries;
};

int main() {
	Logger& logger = Logger::getInstance();

	logger.log("Error: Can not read the file.");
	logger.log("Info: Data is loaded from the server");

	vector<string> logEntries = logger.getLogs();

	// Print the log entries
	for (const string& entry : logEntries) {
		cout << entry << endl;
	}

	return 0;
}