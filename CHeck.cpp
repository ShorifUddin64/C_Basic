#include <iostream>

using namespace std;

int main() {
    int number;

    // User input
    cout << "Enter a number: ";
    cin >> number;

    // Checking Even or Odd using if-else
    if (number % 2 == 0) {
        cout << number << " is an Even number (Jor shongkha)." << endl;
    } else {
        cout << number << " is an Odd number (Bijor shongkha)." << endl;
    }

    cout << "\n--- Multiplication Table for " << number << " ---\n";

    // Simple For Loop for Namta
    for (int i = 1; i <= 10; i++) {
        cout << number << " x " << i << " = " << (number * i) << endl;
    }

    return 0;
}