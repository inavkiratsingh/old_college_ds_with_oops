#include <iostream>
using namespace std;

class Area
{
private:
    int length, breadth;

public:
    void Setdim(int l, int b)
    {
        length = l;
        breadth = b;
    }
    int getarearectangle()
    {
        return length * breadth;
    }
    int getareacircle()
    {
        return 3.14159 * length * length;
    }
    int getareatriangle()
    {
        return 0.5 * length * breadth;
    }
};

int main()
{
    Area object;
    int l, b;

    cout << "Enter Length :";
    cin >> l;
    cout << "Enter Breadth :";
    cin >> b;

    object.Setdim(l, b);

    cout << "Area of Rectangle:" << object.getarearectangle() << endl;
    cout << "Area of Circle:" << object.getareacircle() << endl;
    cout << "Area of Triangle:" << object.getareatriangle() << endl;

    return 0;
}