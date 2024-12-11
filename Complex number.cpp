//Implement a class Complex which represents the Complex Number data type. Implement
//the following operations:
//1. Constructor (including a default constructor which creates the complex number 0+0i).
//2. Overloaded operator+ to add two complex numbers.
//3. Overloaded operator* to multiply two complex numbers.
//4. Overloaded << and >> to print and read Complex Numbers
#include <iostream>
using namespace std;

class Complex {
private:
    int x, y; // Real and imaginary parts

public:
    // Default constructor
    Complex() : x(0), y(0) {}

    // Parameterized constructor
    Complex(int real, int img) : x(real), y(img) {}

    // Overloaded + operator
    Complex operator+(const Complex &c) const {
        return Complex(x + c.x, y + c.y);
    }

    // Overloaded * operator
    Complex operator*(const Complex &c) const {
        return Complex((x * c.x - y * c.y), (y * c.x + x * c.y));
    }

    // Friend function for input operator overloading
    friend istream &operator>>(istream &in, Complex &c) {
        cout << "Enter real part: ";
        in >> c.x;
        cout << "Enter imaginary part: ";
        in >> c.y;
        return in;
    }

    // Friend function for output operator overloading
    friend ostream &operator<<(ostream &out, const Complex &c) {
        out << c.x;
        if (c.y >= 0)
            out << "+";
        out << c.y << "i";
        return out;
    }
};

int main() {
    // Default constructor
    Complex c1;
    cout << "Default complex number: " << c1 << endl;

    // Parameterized constructor
    Complex c2(2, 5);
    cout << "Parameterized complex number: " << c2 << endl;

    // Taking user input for complex numbers
    Complex c3, c4;
    cout << "Enter the first complex number:" << endl;
    cin >> c3;

    cout << "Enter the second complex number:" << endl;
    cin >> c4;

    // Adding two complex numbers
    Complex c5 = c3 + c4;
    cout << "Sum of the complex numbers: " << c5 << endl;

    // Multiplying two complex numbers
    c5 = c3 * c4;
    cout << "Product of the complex numbers: " << c5 << endl;

    return 0;
}
