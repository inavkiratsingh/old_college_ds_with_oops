#include <iostream>
using namespace std;

class Stack
{
private:
    static const int maxSize = 100;
    int top;
    int *array_stack;

public:
    Stack()
    {
        array_stack = new int[maxSize];
        top = -1;
    }
    ~Stack()
    {
        delete[] array_stack;
    }

    void push(int item)
    {
        if (top >= maxSize - 1)
        {
            cout << "Stack is Overflow. Cannot push any item." << endl;
        }
        else
        {
            top++;
            array_stack[top] = item;
            cout << "Pushed item: " << item << endl;
        }
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Empty stack" << endl;
        }
        else
        {
            for (int i = 0; i <= top; i++)
            {
                cout << array_stack[i] << " ";
            }
            cout << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is Underflow" << endl;
        }
        else
        {
            cout << "Popped item: " << array_stack[top] << endl;
            top--;
        }
    }

    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            cout << "Top element: " << array_stack[top] << endl;
        }
    }

    void search(int item)
    {
        int found = -1;
        for (int i = 0; i <= top; i++)
        {
            if (array_stack[i] == item)
            {
                found = i;
                break;
            }
        }
        if (found != -1)
        {
            cout << "Item found at position " << found << endl;
        }
        else
        {
            cout << "Item not found." << endl;
        }
    }

    void copy(Stack & destination)
    {
        for (int i = 0; i <= top; i++)
        {
            destination.push(array_stack[i]);
        }
    }
};

int main()
{
    int choice, n, value;
    Stack stack;
    Stack copiedStack;

    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        stack.push(value);
    }

again:

    cout << "Stack Menu:" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Search" << endl;
    cout << "5. Display" << endl;
    cout << "6. Copy" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter value to push: ";
        cin >> value;
        stack.push(value);
        cout<<"Updated Stack:";
        stack.display();
        break;
    case 2:
        stack.pop();
        cout<<"Updated Stack:";
        stack.display();
        break;
    case 3:
        stack.peek();
        cout<<"Updated Stack:";
        stack.display();
        break;
    case 4:
        cout << "Enter value to search: ";
        cin >> value;
        stack.search(value);
        break;
    case 5:
    cout<<"Updated Stack:";
        stack.display();
        break;
    case 6:
        stack.copy(copiedStack);
        cout << "Stack copied." << endl;
        break;
    case 7:
        cout << "Exiting program." << endl;
        return 0;
    default:
        cout << "Invalid choice. Please try again." << endl;
    }

    char chs;
    cout << "\n\nEnter y for the main menu and n to exit this program: ";
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