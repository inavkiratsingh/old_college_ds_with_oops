// First Program

#include <iostream>
using namespace std;

int main() {
    string name;
    int roll_no;
    int semester;
    string branch;
    string institution;

    // Input values
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Roll no: ";
    cin >> roll_no;

    cout << "Enter Semester: ";
    cin >> semester;

    cout << "Enter Branch: ";
    getline(cin, branch);

    cout << "Enter Institution: ";
    getline(cin, institution);

    // Display the entered information
    cout << "Name - " << name << endl;
    cout << "Roll no. " << roll_no << endl;
    cout << "Semester - " << semester << endl;
    cout << "Branch - " << branch << endl;
    cout << "Institution - " << institution << endl;

    return 0;
}
