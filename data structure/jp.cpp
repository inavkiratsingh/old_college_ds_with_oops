#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(const vector<int> &a)
{
    for (int element : a)
    {
        cout << element << " ";
    }
    cout << endl;
}

void insert(vector<int> &arr, int n, int l)
{
    if (l >= 0 && l <= arr.size())
    {
        arr.insert(arr.begin() + l, n);
        cout << "Updated array after insertion: ";
        display(arr);
    }
    else
    {
        cout << "Invalid position." << endl;
    }
}

void dlt(vector<int> &arr, int l)
{
    if (l >= 0 && l < arr.size())
    {
        arr.erase(arr.begin() + l);
        cout << "Updated array after deletion: ";
        display(arr);
    }
    else
    {
        cout << "Invalid position." << endl;
    }
}

void search(const vector<int> &a, int n)
{
    auto it = find(a.begin(), a.end(), n);
    if (it != a.end())
    {
        cout << "Element found at index: " << distance(a.begin(), it) << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }
}

void possibilities(const vector<int> &data)
{
    // Find the maximum element 
    int maxElement = *max_element(data.begin(), data.end());

    // Create a frequency array to count each element
    vector<int> frequency(maxElement + 1, 0);
    for (int num : data)
    {
        frequency[num]++;
    }

    // Display the histogram
    for (int i = 0; i <= maxElement; i++)
    {
        cout << i << " -- ";
        for (int j = 0; j < frequency[i]; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}

int main()
{
    vector<int> Arr;
    vector<int> Even;
    vector<int> Odd;
    int elements;

    cout << "Enter Number of Elements: ";
    cin >> elements;

    int value;
    for (int i = 0; i < elements; i++)
    {
        cout << "\nEnter value " << i + 1 << ": ";
        cin >> value;
        if (value % 2 == 0)
        {
            std::cout << "value is even and also added to the even array";
            Even.push_back(value);
        }
        else
        {
            std::cout << "value is odd and also added to the odd array";
            Odd.push_back(value);
        }
        Arr.push_back(value);
    }
again:
    // Switch Case:
    int option;
    cout << "\n Options:\n";
    cout << "1. Insert value\n";
    cout << "2. Delete a value\n";
    cout << "3. Search a value\n";
    cout << "4. Display values\n";
    cout << "5. Exit\n";
    cout << "6. Know the maximum and minimum numbers\n";
    cout << "Enter Your Option: ";
    cin >> option;

    switch (option)
    {
    case 1:
        int element, location;
        cout << "Enter the element to insert: ";
        cin >> element;
        cout << "Enter the location: ";
        cin >> location;
        insert(Arr, element, location - 1);
        break;
    case 2:
        int delete_location;
        cout << "Enter the location of the element you want to delete: ";
        cin >> delete_location;
        dlt(Arr, delete_location - 1);
        break;
    case 3:
        int search_element;
        cout << "Enter the value to search: ";
        cin >> search_element;
        search(Arr, search_element);
        break;
    case 4:
        cout << "All the elements of array : ";
        display(Arr);
        cout << "\nIf you want to display even elements then press \"e\" \nfor odd elements press\"o\" \nfor even press \"b\" : ";
        char dischoice;
        cin >> dischoice;
        if (dischoice == 'e')
        {
            display(Even);
        }
        else if (dischoice == 'o')
        {
            display(Odd);
        }
        else
        {
            display(Even);
            display(Odd);
        }

        cout<<"\n\nHere is the posibilities of the number you entered\n";
        possibilities(Arr);
        break;
    case 5:
        cout << "Exiting the program.\n";
        sort(Arr.begin(), Arr.end());
        display(Arr);
        break;
    case 6:
        sort(Arr.begin(), Arr.end());
        cout << "Minimum number in your array is : ";
        cout << Arr[0];
        cout << "\nMaximum number in your array is :";
        cout << Arr[elements - 1];
        break;
    default:
        cout << "Invalid option. Please try again.\n";
        break;
    }

    char cond;
    cout << "\nEnter y if u want to perform another operation and n for exit the program : ";
    cin >> cond;

    if (cond == 'y')
        goto again;
    else
        exit(1);

    return 0;
}