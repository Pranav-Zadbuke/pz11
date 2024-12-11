//Imagine a publishing company which does marketing for book and audiocassette versions. Create a
//class publication that stores the title (a string) and price (type float) of a publication. From this class
//derive two classes: book, which adds a page count (type int), and tape, which adds a playing time in
//minutes (type float). Write a program that instantiates the book and tape classes, allows user to enter
//data and displays the data members. If an exception is caught, replace all the data member values with
//zero values.
#include <iostream>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0) {}

    void getPublicationDetails() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    void displayPublicationDetails() const {
        cout << "Title: " << title << "\nPrice: " << price << endl;
    }
};

class Book : public Publication {
private:
    int pages;

public:
    Book() : pages(0) {}

    void getDetails() {
        getPublicationDetails();
        cout << "Enter number of pages: ";
        cin >> pages;

        if (pages < 500 || pages > 1500 || price < 100 || price > 2000) {
            throw "Invalid book details!";
        }
    }

    void displayDetails() const {
        displayPublicationDetails();
        cout << "Pages: " << pages << endl;
    }
};

class Tape : public Publication {
private:
    float playTime;

public:
    Tape() : playTime(0.0) {}

    void getDetails() {
        getPublicationDetails();
        cout << "Enter playing time (in minutes): ";
        cin >> playTime;

        if (playTime < 30.0 || playTime > 90.0 || price < 500 || price > 1000) {
            throw "Invalid tape details!";
        }
    }

    void displayDetails() const {
        displayPublicationDetails();
        cout << "Playing Time: " << playTime << " minutes" << endl;
    }
};

int main() {
    int choice;
    cout << "Do you want to buy a book (Press 1) or a tape (Press 2): ";
    cin >> choice;

    try {
        if (choice == 1) {
            Book book;
            book.getDetails();
            cout << "\nBook Details:\n";
            book.displayDetails();
        } else if (choice == 2) {
            Tape tape;
            tape.getDetails();
            cout << "\nTape Details:\n";
            tape.displayDetails();
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    } catch (const char* error) {
        cout << "Error: " << error << endl;
    }

    return 0;
}
