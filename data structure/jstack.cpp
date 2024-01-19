#include <iostream>
using namespace std;

const int maxsize1 = 5;
const int maxsize2 = 6;
int topA = -1;
int topB = -1;
int topeven = -1;
int topodd = -1;
int stackA[maxsize1];
int stackB[maxsize2];
int oA = -1, oB = -1;
int stackAo[maxsize1];
int stackBo[maxsize1];
int even_stack[maxsize1];
int odd_stack[maxsize1];

void valuevaps()
{
    if (oA > -1)
    {
        ++topA;
        stackA[topA] = stackAo[oA];
        oA--;
    }
    if (oB > -1)
    {
        ++topB;
        stackB[topB] = stackBo[oB];
        oB--;
    }
}

void pushA(int item)
{
    if (topA >= maxsize1 - 1)
    {
        cout << "Stack A is Overflow. Cannot push any more items." << endl;
    }
    else
    {
        stackA[++topA] = item;
        cout << "Pushed item " << item << " to Stack A." << endl;
    }
}

void pushB(int item)
{
    if (topB >= maxsize2 - 1)
    {
        cout << "Stack B is Overflow. Cannot push any more items." << endl;
    }
    else
    {
        stackB[++topB] = item;
        cout << "Pushed item " << item << " to Stack B." << endl;
    }
}

void display(int stackc[maxsize2], int top)
{
    for (int i = 0; i <= top; i++)
    {
        cout << stackc[i] << " ";
    }
    cout << endl;
}

void pop()
{
    while (topA > -1 && topB > -1)
    {
        if (stackA[topA] % 2 == 0 && stackB[topB] % 2 == 0)
        {
            topeven++;
            even_stack[topeven] = stackA[topA] + stackB[topB];
            cout << "Popped even item: " << stackA[topA] << " + " << stackB[topB] << " = " << even_stack[topeven] << endl;
            topA--;
            topB--;
            valuevaps();
        }
        else if (stackA[topA] % 2 != 0 && stackB[topB] % 2 != 0)
        {
            topodd++;
            odd_stack[topodd] = stackA[topA] + stackB[topB];
            cout << "Popped odd item: " << stackA[topA] << " + " << stackB[topB] << " = " << odd_stack[topodd] << endl;
            topA--;
            topB--;
            valuevaps();
        }
        else if (stackA[topA] % 2 != 0 && stackB[topB] % 2 == 0)
        {
            oA++;
            stackAo[oA] = stackA[topA];
            cout << "popped item from stack A:" << stackA[topA];
            topA--;
        }
        else if (stackA[topA] % 2 == 0 && stackB[topB] % 2 != 0)
        {
            oB++;
            stackBo[oB] = stackB[topB];
            cout << "popped item from stack B :" << stackB[topB] << endl;
            topB--;
        }
    }

    // else if (topA >= 0)
    // {
    //     cout << "Stack B is Empty. Popping remaining items from Stack A:" << endl;
    //     while (topA >= 0)
    //     {
    //         cout << "Popped item from Stack A: " << stackA[topA] << endl;
    //         topA--;
    //     }
    // }
    // else if (topB >= 0)
    // {
    //     cout << "Stack A is Empty. Popping remaining items from Stack B:" << endl;
    //     while (topB >= 0)
    //     {
    //         cout << "Popped item from Stack B: " << stackB[topB] << endl;
    //         topB--;
    //     }
    // }
}

void peek()
{
    if (topA == -1 && topB == -1)
    {
        cout << "Both Stack A and Stack B are Empty" << endl;
    }
    else
    {
        cout << "Top element of Stack A: " << ((topA >= 0) ? stackA[topA] : -1) << endl;
        cout << "Top element of Stack B: " << ((topB >= 0) ? stackB[topB] : -1) << endl;
    }
}

int main()
{
    int n, choice, value;
    cout << "Enter elements in Stack A: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value " << i + 1 << ": " << endl;
        cin >> value;
        pushA(value);
    }

    cout << "\nEnter elements in Stack B: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value " << i + 1 << " : " << endl;
        cin >> value;
        pushB(value);
    }
    {
    again:
        cout << "Stack Menu:" << endl;
        cout << "1. Push item to Stack A" << endl;
        cout << "2. Push item to Stack B" << endl;
        cout << "3. Pop" << endl;
        cout << "4. Peek" << endl;
        cout << "5. Display Even Stack" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push in Stack A: ";
            cin >> value;
            pushA(value);
            break;
        case 2:
            cout << "Enter value to push in Stack B: ";
            cin >> value;
            pushB(value);
            break;
        case 3: 

            display(stackA, topA);
            display(stackB, topB);
            pop();
            display(even_stack, topeven);
            display(odd_stack, topodd);
            break;
        case 4:
            peek();
            break;
        case 5:
            cout << "Even Stack: ";
            display(even_stack, topeven);
            cout << "Odd Stack:";
            display(odd_stack, topodd);
            break;
        case 6:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
    char chs;
    cout << "\n\nEnter y for main menu and n for exit this program : ";
    cin >> chs;
    if (chs == 'y')
    {
        goto again;
    }
    else
    {
        exit(1);
    }
    return 0;
}