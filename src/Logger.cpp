#include "Logger.h"

unordered_map<string, vector<pair<string, int>>> Logger::parseLog(const vector<string>& logs) {
    unordered_map<string, vector<pair<string, int>>> interactions;

    for (const auto& entry : logs) {
        istringstream ss(entry);
        string personA, personB, timeStr;

        if (!getline(ss, personA, ',') || !getline(ss, personB, ',') || !getline(ss, timeStr, ',')) {
            cerr << "[ERROR] Skipping invalid log entry: Malformed log entry: " << entry << endl;
            continue;
        }

        if (timeStr.empty() || timeStr.find_first_not_of("0123456789") != string::npos) {
            cerr << "[ERROR] Skipping invalid log entry: Invalid time value: " << entry << endl;
            continue;
        }

        int time = stoi(timeStr);
        if (time < 0) {
            cerr << "[ERROR] Skipping invalid log entry: Negative timestamp: " << entry << endl;
            continue;
        }

        // Store interactions in bidirectional mapping
        interactions[personA].push_back({personB, time});
        interactions[personB].push_back({personA, time});
    }

    if (interactions.empty()) {
        throw runtime_error("Error: No valid log entries found!");
    }

    return interactions;
}