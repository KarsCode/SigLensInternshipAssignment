#include <iostream>
#include "Logger.h"
#include "ContactTracer.h"

using namespace std;

int main() {
    try {
        // Example input data
        vector<string> logs = {
            "P1,Q1,10",
            "Q1,R1,20",
            "S1,T1,30",
            "T1,U1,40"
        };
        
        vector<string> initiallyInfected = {
            "P1", "S1"
        };
        
        int contagiousPeriod = 48;

        // Parse interaction logs
        auto logData = Logger::parseLog(logs);

        // Initialize Contact Tracer
        ContactTracer tracer(logData, contagiousPeriod);

        // Get infected list
        auto infectedPeople = tracer.traceInfection(initiallyInfected);

        // Output results
        cout << "Infected individuals: ";
        for (const auto& person : infectedPeople) {
            cout << person << " ";
        }
        cout << endl;

        // Example usage of findContacts
        // string personToCheck = "A1";
        // int timeToCheck = 10;
        // int window = 20;
        // auto contacts = tracer.findContacts(personToCheck, timeToCheck, window);
        // cout << "Contacts of " << personToCheck << " around time " << timeToCheck << " within a window of " << window << ": ";
        // for (const auto& contact : contacts) {
        //     cout << contact << " ";
        // }
        cout << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}