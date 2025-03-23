#ifndef LOGGER_H
#define LOGGER_H

#include <unordered_map>
#include <vector>
#include <string>
#include <utility>
#include <sstream>
#include <iostream>

using namespace std;

class Logger {
public:
    static unordered_map<string, vector<pair<string, int>>> parseLog(const vector<string>& logs);
};

#endif