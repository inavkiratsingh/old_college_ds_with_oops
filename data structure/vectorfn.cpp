#include <iostream>
#include <vector>
#include <algorithm>

void display(const std::vector<int> &v)
{
    for (int n : v)
        std::cout << n << " ";
}

void inst(std::vector<int> &ins, int n, int l)
{
    ins.insert(ins.begin() + l, n);
    std::cout << "Updated array : ";
    display(ins);
}

void dlt(std::vector<int> &del, int l)
{
    if (l >= 0 && l < del.size())
    {
        del.erase(del.begin() + l);
        std::cout << "Updated array : ";
        display(del);
    }
}

int searchlocation(const std::vector<int> &srch, int n)
{
    auto it = std::find(srch.begin(), srch.end(), n);
    if (it != srch.end())
    {
        return std::distance(srch.begin(), it);
    }
    else
    {
        return -1; // element not found in the current array
    }
}

int main()
{
    std::vector<int> vctor;
    std::vector<int> undo;
    int elements;

    std::cout << "Enter Number of elements : ";
    std::cin >> elements;

    int temp;
    std::cout << "\nEnter the values of array here : \n";
    for (int i = 0; i < elements; i++)
    {
        std::cout << "Enter " << i + 1 << " value : ";
        std::cin >> temp;
        vctor.push_back(temp);
    }

again:

    int choice;
    std::cout << "\nEnter following values to perform the particular operation";
    std::cout << "\n\n1. For insert a value";
    std::cout << "\n2. For delete a value";
    std::cout << "\n3. For search a value";
    std::cout << "\n4. For display the vector";
    std::cout << "\n5. Exit";

    std::cout << "\n\nEnter your choice : ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        int n, l;
        std::cout << "\nEnter the element to insert : ";
        std::cin >> n;
        std::cout << "Enter the location : ";
        std::cin >> l;
        std::cout << std::endl;
        inst(vctor, n, l - 1);
        break;
    case 2:
        undo = vctor;
        std::cout << "Enter the location of the element you want to delete : ";
        std::cin >> l;
        dlt(vctor, l - 1);

        char undochoice;
        std::cout << "\nEnter a \"u\" if you want to undo or \"n\" for go to main menu : \n";
        std::cin >> undochoice;

        if (undochoice == 'u')
        {
            vctor = undo;
            std::cout << "After undo array is : ";
            display(vctor);
        }
        else
        {
            goto again;
        }
        break;
    case 3:
        std::cout << "Enter the element to find : ";
        std::cin >> n;
        l = searchlocation(vctor, n);
        if (l != -1)
        {
            std::cout << "Element " << n << " found at location " << l + 1 << ". \n";
        }
        else
        {
            std::cout << "Element not found in the current array. \n";
        }
        break;
    case 4:
        std::cout << "Current array elements are : \n";
        display(vctor);
        break;
    case 5:
        exit(1);
        break;
    default:
        std::cout << "Error :: Enter a valid value.";
        break;
    }

    char n;
    std::cout << "\n\nEnter y for main menu and n for exit this program : ";
    std::cin >> n;
    if (n == 'y')
    {
        goto again;
    }
    else
    {
        exit(1);
    }

    return 0;
}
