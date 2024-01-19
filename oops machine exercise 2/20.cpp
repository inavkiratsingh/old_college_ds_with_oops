#include <iostream>
using namespace std;

void swap(int *first_no, int *second_no)
{
    *first_no = *first_no + *second_no;
    *second_no = *first_no - *second_no;
    *first_no = *first_no - *second_no;
}

int main()
{
    int num1, num2;
    cout << "enter first number :";
    cin >> num1;
    cout << "enter second number :";
    cin >> num2;

    cout << "Before Swaping :" << num1 << num2 << endl;

    swap(&num1, &num2);
    cout << "Ater swaping :" << num1 << num2;

    return 0;
}