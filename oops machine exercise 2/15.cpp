#include <iostream>
using namespace std;

class Average {
public:
    static void calculateAndPrintAverage(double num1, double num2, double num3) {
        double average = (num1 + num2 + num3) / 3.0;
        cout << "Average of the three numbers: " << average << endl;
    }
};

int main() {
    double num1, num2, num3;

    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    Average::calculateAndPrintAverage(num1, num2, num3);

    return 0;
}
