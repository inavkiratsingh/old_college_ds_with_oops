#include <iostream>
#include <cmath>
using namespace std;

double rectangle_area(double length, double width) {
    return length * width;
}

double rectangle_perimeter(double length, double width) {
    return 2 * (length + width);
}

double square_area(double side) {
    return side * side;
}

double square_perimeter(double side) {
    return 4 * side;
}

double triangle_area(double base, double height) {
    return 0.5 * base * height;
}

double circle_area(double radius) {
    return M_PI * radius * radius;
}

double circle_circumference(double radius) {
    return 2 * M_PI * radius;
}

double cone_surface_area(double radius, double height) {
    double slant_height = sqrt(radius * radius + height * height);
    double base_area = circle_area(radius);
    double lateral_area = M_PI * radius * slant_height;
    return base_area + lateral_area;
}

double cone_volume(double radius, double height) {
    return (1/3.0) * M_PI * radius * radius * height;
}

double cylinder_surface_area(double radius, double height) {
    double base_area = 2 * circle_area(radius);
    double lateral_area = 2 * M_PI * radius * height;
    return base_area + lateral_area;
}

double cylinder_volume(double radius, double height) {
    return M_PI * radius * radius * height;
}

int main() {
    while (true) {
        cout << "Shapes:" << endl;
        cout << "1. Rectangle" << endl;
        cout << "2. Square" << endl;
        cout << "3. Triangle" << endl;
        cout << "4. Circle" << endl;
        cout << "5. Cone" << endl;
        cout << "6. Cylinder" << endl;
        cout << "7. Exit" << endl;

        int choice;
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        if (choice == 1) {
            double length, width;
            cout << "Enter length: ";
            cin >> length;
            cout << "Enter width: ";
            cin >> width;
            cout << "Area: " << rectangle_area(length, width) << endl;
            cout << "Perimeter: " << rectangle_perimeter(length, width) << endl;
        } else if (choice == 2) {
            double side;
            cout << "Enter side length: ";
            cin >> side;
            cout << "Area: " << square_area(side) << endl;
            cout << "Perimeter: " << square_perimeter(side) << endl;
        } else if (choice == 3) {
            double base, height;
            cout << "Enter base length: ";
            cin >> base;
            cout << "Enter height: ";
            cin >> height;
            cout << "Area: " << triangle_area(base, height) << endl;
        } else if (choice == 4) {
            double radius;
            cout << "Enter radius: ";
            cin >> radius;
            cout << "Area: " << circle_area(radius) << endl;
            cout << "Circumference: " << circle_circumference(radius) << endl;
        } else if (choice == 5) {
            double radius, height;
            cout << "Enter base radius: ";
            cin >> radius;
            cout << "Enter height: ";
            cin >> height;
            cout << "Surface Area: " << cone_surface_area(radius, height) << endl;
            cout << "Volume: " << cone_volume(radius, height) << endl;
        } else if (choice == 6) {
            double radius, height;
            cout << "Enter base radius: ";
            cin >> radius;
            cout << "Enter height: ";
            cin >> height;
            cout << "Surface Area: " << cylinder_surface_area(radius, height) << endl;
            cout << "Volume: " << cylinder_volume(radius, height) << endl;
        } else if (choice == 7) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
