//Write a program in C++ to use map associative container. The keys will be the names of states and the
//values will be the populations of the states. When the program runs, the user is prompted to type the
//name of a state. The program then looks in the map, using the state name as an index and returns the
//population of the state.
#include <iostream>
#include <map>
#include <string>
#include <limits>
using namespace std;

int main() {
    // Map to store state names and their populations in millions
    map<string, int> populationMap = {
        {"Maharashtra", 125}, {"Uttar Pradesh", 225}, {"Bihar", 120},
        {"West Bengal", 100}, {"Madhya Pradesh", 90}, {"Tamil Nadu", 80},
        {"Rajasthan", 78}, {"Andhra Pradesh", 53}, {"Odisha", 47},
        {"Kerala", 38}, {"Telangana", 37}, {"Assam", 35},
        {"Jharkhand", 38}, {"Karnataka", 68}, {"Gujarat", 70},
        {"Punjab", 31}, {"Chhattisgarh", 30}, {"Haryana", 29},
        {"UT Delhi", 19}, {"UT Jammu and Kashmir", 14}, {"Uttarakhand", 12},
        {"Himachal Pradesh", 8}
    };

    // Display all states and their populations
    cout << "States and Union Territories with their populations:\n";
    for (const auto& entry : populationMap) {
        cout << entry.first << ": " << entry.second << " million\n";
    }

    char choice;
    do {
        string state;
        cout << "\nEnter the state you want to know the population of: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        getline(cin, state); // Accept multi-word input for states like "West Bengal"

        auto it = populationMap.find(state);
        if (it != populationMap.end()) {
            cout << state << "'s population is " << it->second << " million\n";
        } else {
            cout << "State not found in the population map.\n";
        }

        cout << "Do you wish to continue? (y/n): ";
        cin >> choice;
    } while (tolower(choice) == 'y');

    return 0;
}
