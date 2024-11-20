#include <bits/stdc++.h>
using namespace std;

class Student
{
    public:
    int roll;
    int cls;
    double gpa;
 //constructor->1. constructor class er vitrei take,2. er return type thake na,3.er nam hy exactly class er nam e
    Student(int roll, int cls, double gpa) // diff perameter na dile must "this" use kora lagbe, other wise na krleu prb nai
    {
        (*this).roll=roll;
        (*this).cls =cls;
        (*this).gpa= gpa;

    } 

};

int main()
{
    Student Rahim(45,5,3.3);

    Student* karim=new Student(10,5,3.9); //dynamic obj|| new keyword heap memory ke access korte pare

   cout<< Rahim.roll << " " << Rahim.cls << " " << Rahim.gpa << endl;
   cout<< karim->roll << " " << karim->cls << " " << karim->gpa << endl;

}