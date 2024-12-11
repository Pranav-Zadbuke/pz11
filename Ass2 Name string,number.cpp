//string name ,phone number,address

#include <iostream>
using namespace std;

class Student {
private:
    char name[50], class1[10], div[5], dob[15], bldgrp[5], address[100], drv[20];
    int rno, phone;
    static int counter;

public:
    Student() {
        // Initialize all character arrays to empty strings
        name[0] = class1[0] = div[0] = dob[0] = bldgrp[0] = address[0] = drv[0] = '\0';
        rno = 0;
        phone = 0;
    }

    void getDetails() {
        cout << "\nEnter the details of the student:\n";
        cout << "Name: ";
        cin >> name;
        cout << "Roll No.: ";
        cin >> rno;
        cout << "Class: ";
        cin >> class1;
        cout << "Division: ";
        cin >> div;
        cout << "Address: ";
        cin >> address;
        cout << "Phone: ";
        cin >> phone;
        cout << "Date of Birth: ";
        cin >> dob;
        cout << "Driving License: ";
        cin >> drv;
        cout << "Blood Group: ";
        cin >> bldgrp;
    }

    void showDetails() {
        counter++;
        cout << "\n*************** Details of Student " << counter << " ***************\n";
        cout << "Name: " << name << "\n";
        cout << "Roll No.: " << rno << "\n";
        cout << "Class: " << class1 << "\n";
        cout << "Division: " << div << "\n";
        cout << "Address: " << address << "\n";
        cout << "Phone: " << phone << "\n";
        cout << "Date of Birth: " << dob << "\n";
        cout << "Driving License: " << drv << "\n";
        cout << "Blood Group: " << bldgrp << "\n";
    }
};

int Student::counter = 0;

int main() {
    cout << "How many students do you want to enter? ";
    int num;
    cin >> num;

    Student students[num];
    for (int i = 0; i < num; i++) {
        students[i].getDetails();
    }

    cout << "\n*************** Student Information ***************\n";
    for (int i = 0; i < num; i++) {
        students[i].showDetails();
    }

    return 0;
}
