//Write a function template selection Sort. Write a program that inputs, sorts and outputs an int array
//and a float array.

#include <iostream>
using namespace std;

#define SIZE 10

template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the current element with the smallest element
        T temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Display the sorted array
    cout << "The sorted list is:\n";
    for (int i = 0; i < n; i++) {
        cout << "\t" << arr[i];
    }
    cout << endl;
}

int main() {
    int n;
    int intArray[SIZE];
    float floatArray[SIZE];

    // Handling integer elements
    cout << "Selection Sort - Handling Integer Elements\n";
    cout << "How many elements? ";
    cin >> n;
    cout << "Enter the integer elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> intArray[i];
    }
    selectionSort(intArray, n);

    // Handling float elements
    cout << "\nSelection Sort - Handling Float Elements\n";
    cout << "How many elements? ";
    cin >> n;
    cout << "Enter the float elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> floatArray[i];
    }
    selectionSort(floatArray, n);

    return 0;
}
