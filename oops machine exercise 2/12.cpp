#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double breadth;

public:
    Rectangle(double l, double b) : length(l), breadth(b) {}

    double Area() {
        return length * breadth;
    }
};

int main() {
    // Create two Rectangle objects with sides (4, 5) and (5, 8)
    Rectangle rectangle1(4, 5);
    Rectangle rectangle2(5, 8);

    // Calculate and print the area of the first rectangle
    cout << "Area of the first rectangle: " << rectangle1.Area() << " square units" << endl;

    // Calculate and print the area of the second rectangle
    cout << "Area of the second rectangle: " << rectangle2.Area() << " square units" << endl;

    return 0;
}