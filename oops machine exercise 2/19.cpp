#include <iostream>
using namespace std;

class Distance
{
private:
    int meters;

public:
    Distance(int value)
    {
        meters = value;
        cout << "Initial distance: " << value << endl;
    }
    friend void increment(Distance &object);  // Corrected the friend declaration
    void show();
};

void increment(Distance &object)
{
    object.meters = object.meters + 1;
}

int main()
{
    int value;
    cout << "Initial value of distance: ";
    cin >> value;
    Distance d1(value);
    increment(d1);  
    d1.show(); 
    return 0;
}
