#include <iostream>
using namespace std;
class Student
{
private:
    int rollno;
    char name[20];

public:
    void getinfo()
    {
        cout << "Enter Name of Student:";
        cin.getline(name, 20);
        cout << "Enter Roll no :";
        cin >> rollno;
        cin.ignore();
    }
    void display()
    {
        cout << name<<endl;
        cout << rollno<<endl;
    }
};
class Student_Result : public Student
{
    int marks[5];
    float percentage;

public:
    void Student_marks()
    {
        cout << "Enter marks of 5 Subject:" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter marks for Subject " << i + 1<<":";
            cin >> marks[i];
        }
    }
    void calculate()
    {
        int total_marks = 0;
        for (int i = 0; i < 5; i++)
        {
            total_marks += marks[i];
        }
        percentage =(static_cast<float> (total_marks )/ (5 * 100))* 100;
    }
    void Result_Display()
    {
        cout << " Total Percentage of Student:" << percentage << "%" << endl;
    }
};
int main()
{

    Student_Result student;
    student.getinfo();
    student.Student_marks();
    student.calculate();
    student.display();
    student.Result_Display();

    return 0;
}