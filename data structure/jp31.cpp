#include <iostream>

using namespace std;

struct node
{
    int data;
    node *ptr;
};

node *top = nullptr;

void push(int item)
{
    node *nptr = new node;
    nptr->data = item;
    nptr->ptr = top;
    top = nptr;
}

void pop()
{
    if (top == nullptr)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "Popped element: " << top->data << endl;
        node *tptr = top;
        top = top->ptr;
        delete tptr;
    }
}

void peek()
{
    if (top == nullptr)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Top element is " << top->data << endl;
    }
}

void display()
{
    node *tptr = top;
    if (top == nullptr)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack elements: ";
        while (tptr != nullptr)
        {
            cout << tptr->data << " ";
            tptr = tptr->ptr;
        }
        cout << endl;
    }
}

int main()
{
    int choice, n, value;

    cout << "Enter the number of elements to push onto the stack: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        push(value);
    }

again:
    cout << "\nStack Menu:\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek\n";
    cout << "4. Display\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter element to push: ";
        cin >> value;
        push(value);
        cout << "Updated Stack" << endl;
        display();
        break;
    case 2:
        pop();
        break;
    case 3:
        peek();
        cout << "Updated Stack" << endl;
        display();
        break;
    case 4:
        display();
        break;
    case 5:
        cout << "Exiting the program." << endl;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
    }

    char chs;
    cout << "\n\nEnter y for the main menu and n to exit this program: ";
    cin >> chs;
    if (chs = 'y')
    {
        goto again;
    }
    else
    {
        exit(1); 
    }

    return 0;
}