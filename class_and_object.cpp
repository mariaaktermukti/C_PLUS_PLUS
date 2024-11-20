// how to create class and object in c++ and its implement
#include<bits/stdc++.h>
using namespace std;

class Student //user define data type
{
    public:
    char name[100];
    int roll;
    double gpa;
};

int main()
{
    Student a; 
    a.gpa=3.96;
    a.name;
    a.roll=10;
    char temp[100]="Sakib";
    strcpy(a.name, temp);

    cout<< a.name << " " << a.roll << " " << a.gpa << endl;
    return 0;
}