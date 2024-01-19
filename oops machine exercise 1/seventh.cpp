// sixth program
#include <iostream>

using namespace std;

int main() {
    int numbers[10];
    int evenCount = 0, oddCount = 0, zeroCount = 0;

    // Input the array elements
    for (int i = 0; i < 10; ++i) {
        cout << "Enter " << i + 1 << " value : ";
        cin >> numbers[i];
    }

    // Count even and odd numbers
    for (int i = 0; i < 10; ++i) {
        if (numbers[i] == 0) {
            zeroCount++;
        } else if(numbers[i] % 2 == 0){
            evenCount++;
        } else {
            oddCount++;
        }
    }

    cout << "Number of even numbers: " << evenCount << endl;
    cout << "Number of odd numbers: " << oddCount << endl;
    cout << "Count of zeros: " << zeroCount << endl;

    return 0;
}
