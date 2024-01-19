#include <iostream>
using namespace std;

class Area {
private:
    double length;
    double breadth;

public:
    Area(double len, double brd) : length(len), breadth(brd) {}

    double returnArea() {
        return length * breadth;
    }
};

int main() {
    double length, breadth;

    cout << "Enter the length of the rectangle: ";
    cin >> length;

    cout << "Enter the breadth of the rectangle: ";
    cin >> breadth;

    Area rectangle(length, breadth);

    double area = rectangle.returnArea();

    cout << "Area of the rectangle: " << area << " square units" << endl;

    return 0;
}
