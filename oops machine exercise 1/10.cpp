#include <iostream>
#include <string>

using namespace std;

// Define a structure
struct Student
{
    int roll;
    string name;
    double marks;
};

// Define a union
union Money
{
    int dollars;
    double euros;
};

int main()
{
     Student student1;
    cout<<"Size of Student: "<<sizeof(Student)<<"bytes";
    cout<<"\n\nSize of Money: "<<sizeof(Money)<<"bytes";
student1.name="alice";
 student1.roll=01;
 student1.marks=85.5;
 cout<<"\nStudent1.roll: "<<student1.roll<<"\nName:"<<student1.name<<"\nMarks:"<<student1.marks<<endl;

 Money wallet;
 wallet.dollars=50;
 cout<<"\nWallet in Dolllar: "<<wallet.dollars<<endl;

 wallet.dollars=45.75;
 cout<<"\nWallet in Euros: "<<wallet.euros<<endl;
    return 0;
}
