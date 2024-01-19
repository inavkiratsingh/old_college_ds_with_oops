// #include <iostream>

// int main() {

// int totalCalls; std::cout << "Enter the total number of calls: ";
// std::cin >> totalCalls;

// int billAmount = 0;

// if (totalCalls <= 150) {

// // First 150 calls are free
//     billAmount=0;

// } else if (totalCalls <= 400) {

// // Next 250 calls are charged at 1/minute

// billAmount = 250+ (totalCalls-150);

// } else {

// // Calls after 400 are charged at 2/minute
// billAmount = 250+ 250+ 2*(totalCalls-400);

// }

// std::cout << "Total bill amount: $" << billAmount << std::endl;

// return 0;
// }

#include <iostream>
using namespace std;

class Student {
    const int sid;
    string sname;

    int marks; // LINE-1

public:
    Student(int a, string b, int c) : sid(a), sname(b), marks(c) {}

    void updateMarks(int x) { marks += x; } // LINE-2

    void print() const { // Add 'const' here
        cout << sid << " : " << sname << " : " << marks;
    }
};

int main() {
    string n;
    int i, m, u;
    cin >> i >> n >> m >> u;
    const Student s1(i, n, m);
    // s1.updateMarks(u); // Error will occur here
    s1.print();
    return 0;
}
