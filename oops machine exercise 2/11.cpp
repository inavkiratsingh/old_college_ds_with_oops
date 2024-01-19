#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
private:
    double side1, side2, side3;
 
public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    double calculatePerimeter() {
        return side1 + side2 + side3;
    }

    double calculateArea() {
        double s = calculatePerimeter() / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    void displayInfo() {
        double perimeter = calculatePerimeter();
        double area = calculateArea();
        cout << "Perimeter of the triangle: " << perimeter << " units" << endl;
        cout << "Area of the triangle: " << area << " square units" << endl;
    }
};

int main() {
    // Create an instance of the Triangle class with sides 3, 4, and 5 units
    Triangle triangle(3, 4, 5);

    // Calculate and display the area and perimeter of the triangle
    triangle.displayInfo();

    return 0;
}
