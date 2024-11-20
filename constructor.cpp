#include <bits/stdc++.h>
using namespace std;

class Student
{
    public:
    int roll;
    int cls;
    double gpa;
 //constructor->1. constructor class er vitrei take,2. er return type thake na,3.er nam hy exactly class er nam e
    Student(int r, int c, double g)
    {
         roll=r;
         cls =c;
         gpa= g;

    } 

};

int main()
{
    Student Rahim(45,5,3.3);

    Student karim(2,5,5.00);

   cout<< Rahim.roll << " " << Rahim.cls << " " << Rahim.gpa << endl;
   cout<< karim.roll << " " << karim.cls << " " << karim.gpa << endl;

}