#include<bits/stdc++.h>
using namespace std;
 class Student
 {
    public:
    string name;
    int roll;
    char section;
    float math_marks;
    char cls;

 //make a constructor
 Student(string n, int r, char s, float mm, char c)
 {
    name=n;
    roll=r;
    section=s;
    math_marks=mm;
    cls=c;
 }
  int getMathMarks()
  {
    return math_marks;
  }
  string getName()
  {
    return name;
  }

 };


int main()
{
    Student s1("Mukti", 1, 'A', 98, 10);
    Student s2("Maria", 2, 'B', 97, 10);
    Student s3("Akter", 3, 'C', 96, 10);

    Student highest= s1;
    if(s2.getMathMarks() > highest.getMathMarks())
    {
        highest= s2;
    }
    if(s3.getMathMarks() > highest.getMathMarks())
    {
        highest= s3;
    }

    cout << "The student with the highest math marks is: " << highest.getName() << " with " 
    << highest.getMathMarks() << " marks." << endl;

    return 0;
}