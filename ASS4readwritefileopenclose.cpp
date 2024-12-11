//Write a C++ program that creates an output file, writes information to it, closes the file and open it
//again as an input file and read the information from the file.
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string fileName, data;

    // Get the file name from the user
    cout << "Enter the name of the file to create: ";
    cin >> fileName;

    // Create and write to the file
    ofstream fout(fileName);
    if (!fout) {
        cerr << "Error creating the file!" << endl;
        return 1;
    }

    cout << "Enter contents for the file (type '^D' on a new line to end):\n";
    cin.ignore(); // Clear the newline character left in the input buffer
    while (getline(cin, data)) {
        if (data == "^D") break; // End input on "^D"
        fout << data << endl;
    }
    fout.close();
    cout << "Data written to the file successfully.\n";

    // Read and display the contents of the file
    ifstream fin(fileName);
    if (!fin) {
        cerr << "Error opening the file for reading!" << endl;
        return 1;
    }

    cout << "Reading from the file:\n";
    while (getline(fin, data)) {
        cout << data << endl;
    }
    fin.close();

    return 0;
}
