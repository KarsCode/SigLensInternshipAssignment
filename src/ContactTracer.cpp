#include "ContactTracer.h"

ContactTracer::ContactTracer(unordered_map<string, vector<pair<string, int>>> logData, int period) {
    if (logData.empty()) throw runtime_error("Error: Log data is empty.");
    if (period <= 0) throw invalid_argument("Error: Contagious period must be positive.");

    interactions = logData;
    contagiousPeriod = period;
}

unordered_set<string> ContactTracer::traceInfection(const vector<string>& initialInfected) {
    unordered_set<string> infectedSet(initialInfected.begin(), initialInfected.end());
    unordered_map<string, int> infectionTimeMap;  // Tracks when each person got infected
    queue<pair<string, int>> toProcess;  // Queue of people to process

    if (infectedSet.empty()) {
        throw runtime_error("Error: No initially infected persons provided.");
    }

    // Initialize queue with initially infected people at time 0
    for (const auto& person : initialInfected) {
        if (interactions.find(person) == interactions.end()) {
            cerr << "[WARNING] Initially infected person not found in logs: " << person << endl;
        }
        infectionTimeMap[person] = 0;  // Initially infected at time 0
        toProcess.push({person, 0});
    }

    while (!toProcess.empty()) {
        auto [currentPerson, infectionTime] = toProcess.front();
        toProcess.pop();

        // Check all contacts of the current person
        for (const auto& [contact, contactTime] : interactions[currentPerson]) {
            // Skip if the contact is already infected
            if (infectedSet.find(contact) != infectedSet.end()) {
                continue;
            }

            // Check if the contact occurred within the contagious period
            if (contactTime >= infectionTime && contactTime <= infectionTime + contagiousPeriod) {
                infectedSet.insert(contact);
                infectionTimeMap[contact] = contactTime;  // Update infection time
                toProcess.push({contact, contactTime});  // Add to queue for further processing
            }
        }
    }

    return infectedSet;
}

vector<string> ContactTracer::findContacts(const string& person, int time, int window) {
    vector<string> contacts;
    if (interactions.find(person) == interactions.end()) {
        cerr << "[WARNING] Person not found in logs: " << person << endl;
        return contacts;
    }

    for (const auto& [contact, contactTime] : interactions[person]) {
        if (contactTime >= time - window && contactTime <= time + window) {
            contacts.push_back(contact);
        }
    }

    return contacts;
}