#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>

using namespace std;

const int MAX_USERS = 100;

class User
{
public:
    string username;
    string password;
};

class SocialMedia
{
private:
    User users[MAX_USERS];
    int userCount;

public:
    SocialMedia() : userCount(0) {}

    void registerUser(const string &username, const string &password)
    {
        if (userCount < MAX_USERS)
        {
            users[userCount].username = username;
            users[userCount].password = password;
            userCount++;
            cout << "Registration successful." << endl;
        }
        else
        {
            cout << "User registration limit reached." << endl;
        }
    }

    bool loginUser(const string &username, const string &password)
    {
        for (int i = 0; i < userCount; i++)
        {
            if (users[i].username == username && users[i].password == password)
            {
                return true;
            }
        }
        return false;
    }
    
    bool searchUser(const string &query)
    {
        cout << "Search Results:" << endl;
        bool found = false;

        for (int i = 0; i < userCount; i++)
        {
            if (users[i].username.find(query) != string::npos)
            {
                cout << "Username: " << users[i].username << endl;
                found = true;
            }
        }

        if (!found)
        {
            cout << "No matching users found." << endl;
        }

        return found;
    }

    void displayMenu()
    {
        cout << "Welcome to the Social Media App!" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Quit" << endl;
    }
};

void appMenu()
{
    int ch;
    cout << "Welcome to the Social Media App!" << endl
         << endl;
    cout << "1. View Recent Updates" << endl;
    cout << "2. Search" << endl;
    cout << "3. View Following List " << endl;
    cout << "4. View Friends List" << endl;
    cout << "5. User Profile" << endl;
    cout << "6. Logout" << endl;
    cout << "Enter your choice : ";
    cin >> ch;
}

string inputPassword()
{
    string password = "";
    char ch;

    while (true)
    {
        ch = _getch();

        if (ch == 13)
        {
            cout << endl;
            break;
        }
        else if (ch == 8)
        {
            if (!password.empty())
            {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else
        {
            password += ch;
            cout << '*';
        }
    }

    return password;
}

int main()
{
    SocialMedia app;
    int choice;

    app.displayMenu();
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        password = inputPassword();
        app.registerUser(username, password);
        break;
    }
    case 2:
    {
        string query;
        cout << "Enter username to search:";
        cin >> query;
        getline(cin,query);
        app.searchUser(query);
        break;
    }
    case 3:
    {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        password = inputPassword();
        if (app.loginUser(username, password))
        {
            cout << "Login successful!" << endl;
        }
        else
        {
            cout << "Login failed. Invalid username or password." << endl;
        }
        break;
    }
    case 4:
        cout << "Goodbye!" << endl;
        break;
    default:
        cout << "Invalid choice. Try again." << endl;
    }
    system("cls");
    appMenu();
    return 0;
}