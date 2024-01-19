#include <iostream>
using namespace std;

class Length {
private:
    int feet;
    float inches;

public:
    Length() {
        feet = 0;
        inches = 0.0;
    }

    Length(int ft, float in) {
        feet = ft;
        inches = in;
    }

    void display() {
        cout << "Feet: " << feet << " Inches: " << inches << endl;
    }

    ~Length() {
        cout << "Destructor called." << endl;
    }
};

int main() {
    int feet;
    float inches;

    cout << "Enter feet: ";
    cin >> feet;
    cout << "Enter inches: ";
    cin >> inches;

    // Create an object of Length class using dynamic constructor
    Length* lengthObj = new Length(feet, inches);

    cout << "Object created using dynamic constructor:" << endl;
    lengthObj->display();

    // Release the dynamically allocated object
    delete lengthObj;

    return 0;
}
