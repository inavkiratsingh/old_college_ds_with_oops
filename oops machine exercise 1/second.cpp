#include <iostream>
using namespace std;

int main() {
    string name;
    int roll_no;
    int semester;
    int marks[5];
    int total_marks = 0;
    double percentage = 0.0;
    string grade;

    // Input values
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Roll no: ";
    cin >> roll_no;

    cout << "Enter Semester: ";
    cin >> semester;

    cout << "Enter Marks in five subjects (out of 100):" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Subject " << i + 1 << ": ";
        cin >> marks[i];
        total_marks += marks[i];
    }

    // Calculate percentage
    percentage = (static_cast<double>(total_marks) / 500) * 100;

    // Determine grade
    if (percentage >= 95) {
        grade = "A+";
    } else if (percentage >= 85) {
        grade = 'A';
    } else if (percentage >= 80) {
        grade = "B+";
    } else if (percentage >= 75) {
        grade = 'B';
    } else if (percentage >= 60) {
        grade = 'C';
    } else {
        grade = "Fail";
    }

    // Display the information
    cout << "Name - " << name << endl;
    cout << "Roll no. " << roll_no << endl;
    cout << "Semester - " << semester << endl;
    cout << "Marks in each subject:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Subject " << i + 1 << ": " << marks[i] << endl;
    }
    cout << "Total marks - " << total_marks << endl;
    cout << "Percentage - " << percentage << "%" << endl;
    cout << "Grade - " << grade << endl;

    return 0;
}
