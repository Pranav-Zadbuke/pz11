//Write a C++ program using STL for sorting and searching user defined records such as personal records
//(Name, DOB, Telephone Number etc.) using vector container.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Item class definition
class Item {
public:
    string name;
    int quantity;
    int cost;
    int code;

    // Overloaded comparison operators
    bool operator==(const Item& other) const {
        return code == other.code;
    }
    bool operator<(const Item& other) const {
        return code < other.code;
    }
};

// Global vector to store items
vector<Item> items;

// Function prototypes
void insertItem();
void displayItems();
void searchItem();
void deleteItem();
void sortItems();

int main() {
    int choice;

    do {
        cout << "\n***** Menu *****";
        cout << "\n1. Insert Item";
        cout << "\n2. Display Items";
        cout << "\n3. Search Item";
        cout << "\n4. Sort Items by Cost";
        cout << "\n5. Delete Item";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertItem(); break;
            case 2: displayItems(); break;
            case 3: searchItem(); break;
            case 4: sortItems(); break;
            case 5: deleteItem(); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

// Insert a new item
void insertItem() {
    Item item;
    cout << "\nEnter Item Name: ";
    cin >> item.name;
    cout << "Enter Item Quantity: ";
    cin >> item.quantity;
    cout << "Enter Item Cost: ";
    cin >> item.cost;
    cout << "Enter Item Code: ";
    cin >> item.code;

    items.push_back(item);
    cout << "Item added successfully!\n";
}

// Display all items
void displayItems() {
    if (items.empty()) {
        cout << "\nNo items to display.\n";
        return;
    }

    for (const auto& item : items) {
        cout << "\nItem Name: " << item.name;
        cout << "\nItem Quantity: " << item.quantity;
        cout << "\nItem Cost: " << item.cost;
        cout << "\nItem Code: " << item.code << "\n";
    }
}

// Search for an item by code
void searchItem() {
    int code;
    cout << "\nEnter Item Code to search: ";
    cin >> code;

    auto it = find_if(items.begin(), items.end(), [&code](const Item& item) {
        return item.code == code;
    });

    if (it != items.end()) {
        cout << "Item found: \n";
        cout << "Name: " << it->name << ", Quantity: " << it->quantity 
             << ", Cost: " << it->cost << ", Code: " << it->code << "\n";
    } else {
        cout << "Item not found.\n";
    }
}

// Delete an item by code
void deleteItem() {
    int code;
    cout << "\nEnter Item Code to delete: ";
    cin >> code;

    auto it = find_if(items.begin(), items.end(), [&code](const Item& item) {
        return item.code == code;
    });

    if (it != items.end()) {
        items.erase(it);
        cout << "Item deleted successfully.\n";
    } else {
        cout << "Item not found.\n";
    }
}

// Sort items by cost
void sortItems() {
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.cost < b.cost;
    });

    cout << "Items sorted by cost.\n";
    displayItems();
}
