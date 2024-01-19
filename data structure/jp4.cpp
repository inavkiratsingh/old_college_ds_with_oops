#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
class Linkedlist
{
private:
    Node *front = 0;
    Node *rear = 0;

public:
    Linkedlist() : front(nullptr), rear(nullptr) {}

    void Enqueue(Node *head, int value)
    {

        Node *newnode = new Node;
        newnode->data = value;
        newnode->next = 0;

        if (front == 0 && rear == 0)
        {
            front = rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }
    void dequeue(Node *head)
    {
        Node *current = head;
        Node *prev = nullptr;
        Node *tptr = head;
        tptr = front;
        if (front == 0 && rear == 0)
        {
            cout << "Queue is empty";
        }
        else
        {
            tptr = front;
            front = front->next;
            delete (tptr);
        }
    }
    void search(int value)
    {
        Node *current = front;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                cout << "Element found " << value << endl;
                return;
            }

            current = current->next;
        }
        cout << "Element not found " << value << endl;
    }
    void size()
    {
        int count = 0;
        Node *current = front;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        cout << "Size of Queue:" << count << endl;
    }

    void display(Node *head)
    {
        Node *current = head;
        current = front;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void clear()
    {
        while (front != nullptr)
        {
            Node *tptr = front;
            front = front->next;
            delete tptr;
        }
        rear = nullptr;
    }
};
int main()
{
    Linkedlist Queue;
    Node *head = nullptr;
    int n, value, choice;  

    cout << "Enter the number of elements in the linked list : ";
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter " << i + 1 << " element : ";
        cin >> value;
        Queue.Enqueue(head, value);
    }
    cout << "\n Queue Linked list elements: ";
    Queue.display(head);
again:

    cout << "\n\t\t\t******* Queue Linked List Operations : *******" << endl;
    cout << "\n1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Search" << endl;
    cout << "4. Display" << endl;
    cout << "5. Queue Size" << endl;
    cout << "6. Clear Queue" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter value to insert: ";
        cin >> value;
        Queue.Enqueue(head, value);
        cout << "Updated Linked List : ";
        Queue.display(head);
        break;
    case 2:
        Queue.dequeue(head);
        cout << "Updated Linked List : ";
        Queue.display(head);
        break;
    case 3:
        cout << "Enter the value to search:";
        cin >> value;
        Queue.search(value);
        break;
    case 4:
        cout << "Updated Linked List : ";
        Queue.display(head);
        break;
    case 5:
        Queue.size();
        break;
    case 6:
        cout << "Queue is cleared" << endl;
        Queue.clear();
        break;

    case 7:
        cout << "Exiting program." << endl;
        exit(1);
        break;

    default:
        cout << "Invalid choice. Please enter a valid option." << endl;
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

    Node *current = head;
    while (current != nullptr)
    {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}