#include <iostream>

using namespace std;

int main() {
    char choice;
    double num1, num2;

    cout << "Select an operation:" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;

    cout << "Enter choice (1/2/3/4): ";
    cin >> choice;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    switch (choice) {
        case '1':
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case '2':
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '3':
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '4':
            if (num2 != 0) {
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            } else {
                cout << "Cannot divide by zero" << endl;
            }
            break;
        default:
            cout << "Invalid input" << endl;
    }

    return 0;
}
