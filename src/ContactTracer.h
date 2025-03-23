#ifndef CONTACTTRACER_H
#define CONTACTTRACER_H

#include <unordered_map>
#include <vector>
#include <string>
#include <utility>
#include <unordered_set>
#include <queue>
#include<stdexcept>
#include <iostream>

using namespace std;

class ContactTracer {
public:
    ContactTracer(unordered_map<string, vector<pair<string, int>>> logData, int period);
    unordered_set<string> traceInfection(const vector<string>& initialInfected);
    vector<string> findContacts(const string& person, int time, int window);

private:
    unordered_map<string, vector<pair<string, int>>> interactions;
    int contagiousPeriod;
};

#endif