#include <iostream>
using namespace std;

// Define the structure for a node in the linked list
struct Node
{
    int data;
    Node *next;
};

// Function to insert a new node at the end of the linked list
void insertNode(Node *&head, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *tptr = head;
        while (tptr->next != nullptr)
        {
            tptr = tptr->next;
        }
        tptr->next = newNode;
    }
}

// Function to insert a value at a specific position in the linked list
void insertAtPosition(Node *&head, int value, int position)
{
    Node *newNode = new Node;
    newNode->data = value;

    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *current = head;
    int currentPosition = 1;

    while (current->next != nullptr && currentPosition < position - 1)
    {
        current = current->next;
        currentPosition++;
    }

    if (current == nullptr)
    {
        cout << "Position out of range." << endl;
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete a node at a specific position from the linked list
void deleteAtPosition(Node *&head, int position)
{
    if (head == nullptr)
    {
        cout << "Linked list is empty." << endl;
        return;
    }

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *current = head;
    Node *prev = nullptr;
    int currentPosition = 1;

    while (current != nullptr && currentPosition < position)
    {
        prev = current;
        current = current->next;
        currentPosition++;
    }

    if (current == nullptr)
    {
        cout << "Position out of range." << endl;
        return;
    }

    prev->next = current->next;
    delete current;
}

// delete by value
void deleteValue(Node *&head, int value)
{
    Node *current = head;
    Node *prev = nullptr;

    while (current != nullptr && current->data != value)
    {
        prev = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Value not found in the linked list." << endl;
        return;
    }

    if (prev == nullptr)
    {
        head = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    delete current;
}

// function to search element
int search_element(Node *&head, int v)
{
    Node *current = head;
    int count = 1;
    while (current->next != nullptr)
    {
        current = current->next;
        count++;
        if (current->data == v)
        {
            return count;
        }
    }
    return 0;
}

Node *reverse(Node *head)
{
    Node *eptr = nullptr;
    Node *tptr = head;
    Node *nextNode = nullptr;

    while (tptr != nullptr)
    {
        nextNode = tptr->next;
        tptr->next = eptr;
        eptr = tptr;
        tptr = nextNode;
    }

    return eptr;
}

// Function to print the linked list
void display(const Node *head)
{
    const Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    int n, choice, value;

    cout << "Enter the number of elements in the linked list : ";
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter " << i + 1 << " element : ";
        cin >> value;
        insertNode(head, value);
    }

    cout << "\nLinked list elements: ";
    display(head);
again:
    cout << "\n\t\t\t*******Linked List Operations : *******" << endl;
    cout << "\n1. Insert at first location" << endl;
    cout << "2. Insert at given location" << endl;
    cout << "3. Insert at end location" << endl;
    cout << "4. Delete" << endl;
    cout << "5. Search" << endl;
    cout << "6. Traverse" << endl;
    cout << "7. Magic" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter value to insert: ";
        cin >> value;
        insertAtPosition(head, value, 1);
        cout << "Updated Linked List : ";
        display(head);
        break;
    case 2:
        int location;
        int insertValue;
        cout << "Enter value to insert: ";
        cin >> insertValue;
        cout << "Enter Location : ";
        cin >> location;
        insertAtPosition(head, insertValue, location);
        cout << "Updated Linked List : ";
        display(head);
        break;
    case 3:
        cout << "Enter value insert at end :";
        cin >> value;
        insertNode(head, value);
        cout << "Updated Linked List : ";
        display(head);
        break;

    case 4:
        char chr;
        cout << "\n\t\t***************************";
        cout << "Plz enter v if you want to delete an element using value or l for using location : ";
        cin >> chr;
        if (chr == 'v')
        {
            cout << "Enter a value : ";
            cin >> value;
            deleteValue(head, value);
        }
        else
        {
            cout << "Enter a location : ";
            cin >> location;
            deleteAtPosition(head, location);
        }
        cout << "Updated Linked List : ";
        display(head);
        break;

    case 5:
        int search;
        int value_search;
        cout << "Enter element to search : ";
        cin >> value_search;
        search = search_element(head, value_search);
        if (search > 0)
        {
            cout << "Element found at location : " << search;
        }
        else
        {
            cout << "Element not found.";
        }
        break;
    case 6:
        cout << "Updated Linked List : ";
        display(head);
        break;
    case 7:
        cout << "Original Linked list is  : ";
        display(head);
        cout << "Reversed Linked list is : ";
        head = reverse(head);
        display(head);
        break;
    case 8:
        cout << "Exiting program." << endl;
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

    // Clean up memory by deleting the linked list
    Node *current = head;
    while (current != nullptr)
    {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}
