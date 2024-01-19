#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int yearOfJoining;
    string address;

public:
    Employee(string n, int year, string addr)
        : name(n), yearOfJoining(year), address(addr) {}

    void displayInfo() {
        cout << name << "\t" << yearOfJoining << "\t\t" << address << endl;
    }
};

int main() {
    // Create three Employee objects with user input
    string name;
    int yearOfJoining;
    string address;

    cout << "Enter information for three employees:" << endl;

    Employee employees[3]; // Create an array to store employee objects

    for (int i = 0; i < 3; i++) {
        cout << "Employee " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> name;
        cout << "Year of Joining: ";
        cin >> yearOfJoining;
        cout << "Address: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, address);
        cout << endl;

        employees[i] = Employee(name, yearOfJoining, address);
    }

    // Print the header
    cout << "Name\tYear of Joining\tAddress" << endl;

    // Display information for each employee
    for (int i = 0; i < 3; i++) {
        employees[i].displayInfo();
    }

    return 0;
}
