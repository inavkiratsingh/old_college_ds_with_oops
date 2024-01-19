#include <iostream>
using namespace std;

// structure for adding a node and which hold the employee data
struct Node
{
    string employeeName;
    int employeeId;
    int employeeSalary;
    Node *ptr;
};

// function to input the values of the linked list
void input(Node *&head, int eid, string name, int es)
{
    Node *newnode = new Node;
    newnode->employeeName = name;
    newnode->employeeId = eid;
    newnode->employeeSalary = es;
    newnode->ptr = nullptr;

    if (head == nullptr)
    {
        head = newnode;
    }
    else
    {
        Node *tptr = head;
        while (tptr->ptr != nullptr)
        {
            tptr = tptr->ptr;
        }
        tptr->ptr = newnode;
    }
}

// Function to insert a value at a specific position in the linked list
void insertAtPosition(Node *&head, int id, string name, int salary, int position)
{
    Node *newnode = new Node;
    newnode->employeeId = id;
    newnode->employeeName = name;
    newnode->employeeSalary = salary;

    if (position == 1)
    {
        newnode->ptr = head;
        head = newnode;
        return;
    }

    Node *tptr = head;
    int currentPosition = 1;

    while (tptr->ptr != nullptr && currentPosition < position - 1)
    {
        tptr = tptr->ptr;
        currentPosition++;
    }

    if (tptr == nullptr)
    {
        cout << "Position out of range." << endl;
        delete newnode;
        return;
    }

    newnode->ptr = tptr->ptr;
    tptr->ptr = newnode;
}

// search
int search_element(Node *&head, int v)
{
    Node *tptr = head;
    int count = 1;
    while (tptr != nullptr)
    {
        count++;
        if (tptr->employeeId == v)
        {
            return count;
        }
        tptr = tptr->ptr;
    }
    return -1;
}

// delete by value
void deleteValue(Node *&head, int value)
{
    Node *tptr = head;
    Node *prev = nullptr;

    while (tptr != nullptr && tptr->employeeId != value)
    {
        prev = tptr;
        tptr = tptr->ptr;
    }

    if (tptr == nullptr)
    {
        cout << "Value not found in the linked list." << endl;
        return;
    }

    if (prev == nullptr)
    {
        head = tptr->ptr;
    }
    else
    {
        prev->ptr = tptr->ptr;
    }

    delete tptr;
}

void displaysalary(Node *head, int v)
{
    Node *tptr = head;
    while (tptr->ptr != nullptr)
    {

        if (tptr->employeeId == v)
        {
            cout << "Employee Id\t\tEmployee Name\t\tEmployee Salary\n";
            cout << tptr->employeeId << "\t\t\t" << tptr->employeeName << "\t\t\t" << tptr->employeeSalary << endl;
            break;
        }
        else
        {
            cout << "Plz enter a valid employee id";
        }
        tptr = tptr->ptr;
    }
}

// function to calculate the bonus
void bonus(Node *head, int v)
{
    int n = 100000;
    Node *tptr = head;
    while (tptr->ptr != nullptr)
    {
        if (tptr->employeeId != v)
        {
            cout << "Plz enter a valid employee id";
        }
        else
        {
            if (tptr->employeeSalary <= n)
            {
                cout << "Salary of the employee is less than 1 lakh so \"NO BONUS\" is apply for this employee so plz check another one.";
                break;
            }
            else
            {
                cout << "Salary of the employee is : " << tptr->employeeSalary << " Bonus is : " << (tptr->employeeSalary / 100) * 10;
                cout << "\nBonus : " << tptr->employeeSalary + (tptr->employeeSalary / 100) * 10;
            }
        }

        tptr = tptr->ptr;
    }
}

// Function to print data in the linked list
void display(const Node *head)
{
    const Node *tptr = head;
    cout << "\n\nEmployee Id\t\tEmployee Name\n";
    while (tptr != nullptr)
    {
        cout << tptr->employeeId << "\t\t\t" << tptr->employeeName << endl;
        tptr = tptr->ptr;
    }
}

void displayWithsalary(const Node *head)
{
    const Node *tptr = head;
    while (tptr != nullptr)
    {
        cout << "\nEmployee id - " << tptr->employeeId << "\nEmployee name - " << tptr->employeeName << "\nEmployee Salary - " << tptr->employeeSalary << endl;
        tptr = tptr->ptr;
    }
}

// sorting of the linked list
void swapId(Node *first, Node *second)
{
    int temp = first->employeeId;
    first->employeeId = second->employeeId;
    second->employeeId = temp;
}

void swapSalary(Node *first, Node *second)
{
    int temp = first->employeeSalary;
    first->employeeSalary = second->employeeSalary;
    second->employeeSalary = temp;
}
void SortLinkedList(Node *head);

int main()
{
    Node *head = nullptr;
    int n;
    int search;
    int eid, esalary;
    string name;
    std::cout << "Enter the number of Employees you want to add in the data : ";
    std::cin >> n;
    std::cout << std::endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "\nEnter the data of " << i + 1 << " employee -- ";
        cout << "\nEnter Employee Name : ";
        cin >> name;
    id_confirm:
        cout << "Enter employee id : ";
        cin >> eid;

        if (eid < 99 || eid > 999)
        {
            cout << "Error PLZ Enter a Employee ID of three numbers only \"for ex - 234, 780, 560\"\n";
            goto id_confirm;
        }

        search = search_element(head, eid);
        if (search < 0)
        {
            cout << "Enter Employee Salary : ";
            cin >> esalary;
            input(head, eid, name, esalary);
        }
        else
        {
            cout << "Error plz enter a valid and unique employee id....\n";
            goto id_confirm;
        }
    }

again:
    int choice;
    std::cout << "\n\t\t\t*******  MAINMENU  :  *******" << std::endl;
    std::cout << "\n1. Want to Add an employee record" << std::endl;
    std::cout << "2. Want to Delete an employee record" << std::endl;
    std::cout << "3. Want to Search an employee" << std::endl;
    std::cout << "4. Display" << std::endl;
    std::cout << "5. Bonus to the employees" << std::endl;
    std::cout << "6. Want to Sort the record" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "\nEnter your choice: ";
    std::cin >> choice;

    switch (choice)
    {

    case 1:
        cout << "\nEnter the data of employee -- ";
        cout << "\nEnter Employee Name : ";
        cin >> name;
    id_con:
        cout << "Enter employee id : ";
        cin >> eid;

        if (eid < 99 || eid > 999)
        {
            cout << "Error PLZ Enter a Employee ID of three numbers only \"for ex - 234, 780, 560\"\n";
            goto id_con;
        }

        search = search_element(head, eid);
        if (search < 0)
        {
            cout << "Enter Employee Salary : ";
            cin >> esalary;
            input(head, eid, name, esalary);
        }
        else
        {
            cout << "Error plz enter a valid and unique employee id....\n";
            goto id_con;
        }
        break;

    case 2:
        cout << "\nEnter an employee ID : ";
        cin >> eid;
        deleteValue(head, eid);
        break;

    case 3:
        int search, value_search;
        cout << "\nEnter employee id You want to search : ";
        cin >> eid;
        displaysalary(head, eid);
        break;

    case 4:
        char ch;
        display(head);
        cout << "\nWant to display the salary of the employee then press s : ";
        cin >> ch;
        if (ch == 's')
        {
            cout << "Enter the employee id of the employee to display the salary : ";
            cin >> eid;
            displaysalary(head, eid);
        }
        break;

    case 5:
    enter:
        cout << "Enter the employee id to see the bonus : ";
        cin >> eid;
        bonus(head, eid);
        cout << "\nWant to check the bonus of the another employee then plz type y : ";
        cin >> ch;
        if (ch == 'y')
        {
            goto enter;
        }
        break;
    case 6:
        cout << "In which method you will like to sort the linked list : \n1. By Employee id\n2. By Employee Salary";
        SortLinkedList(head);
        break;

    case 7:
        cout << "Exciting the program";
        exit(1);
        break;

    default:
        break;
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

void SortLinkedList(Node *head)
{
    Node *tptr;
    Node *eptr;

    int salary_choice;
salarychoice:
    cout << "\nEnter your choice : ";
    cin >> salary_choice;

    if (salary_choice == 1)
    {
        for (tptr = head; tptr != nullptr; tptr = tptr->ptr)
        {
            for (eptr = tptr->ptr; eptr != nullptr; eptr = eptr->ptr)
            {
                if (tptr->employeeId > eptr->employeeId)
                {
                    swapId(tptr, eptr);
                }
            }
        }

        display(head);
    }
    else if (salary_choice == 2)
    {
        for (tptr = head; tptr != nullptr; tptr = tptr->ptr)
        {
            for (eptr = tptr->ptr; eptr != nullptr; eptr = eptr->ptr)
            {
                if (tptr->employeeSalary > eptr->employeeSalary)
                {
                    swapSalary(tptr, eptr);
                }
            }
        }

        displayWithsalary(head);
    }
    else
    {
        cout << "plz enter correct choice : ";
        goto salarychoice;
    }
}
