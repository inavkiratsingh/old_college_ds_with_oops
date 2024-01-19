#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imaginary;

public:
    Complex() {}
    void input()
    {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imaginary;
    }

    Complex add(const Complex &other)
    {

        double add_real = real + other.real;
        double add_imaginary = imaginary + other.imaginary;
        return Complex();
    }

    Complex subtract(Complex other)
    {
        double sub_real = real - other.real;
        double sub_imaginary = imaginary - other.imaginary;
        return Complex();
    }

    Complex multiply(Complex other)
    {

        double prod_real = (real * other.real) - (imaginary * other.imaginary);
        double prod_imaginary = (real * other.imaginary) + (imaginary * other.real);
        return Complex();
    }

    void display()
    {
        cout << real;
        if (imaginary >= 0)
            cout << " + " << imaginary << "i";
        else
            cout << " - " << -imaginary << "i";
        cout << endl;
    }
};

int main()
{
    Complex complex1, complex2;

    cout << "Enter the first complex number:\n";
    complex1.input();

    cout << "Enter the second complex number:\n";
    complex2.input();

    Complex sum = complex1.add(complex2);
    Complex difference = complex1.subtract(complex2);
    Complex product = complex1.multiply(complex2);

    cout << "Sum: ";
    sum.display();

    cout << "Difference: ";
    difference.display();

    cout << "Product: ";
    product.display();

    return 0;
}
