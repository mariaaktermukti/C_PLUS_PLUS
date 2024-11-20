#include <bits/stdc++.h>
using namespace std;

class Student // user-defined data type
{
    public:
    char name[100];
    int roll;
    double gpa;
};

int main()
{
    Student a, b; 

    // Input for Student a
    cin.getline(a.name, 100);  // Read the name
    cin >> a.roll >> a.gpa;    // Read roll and gpa
    cin.ignore();              // Clear the leftover newline from the buffer

    // Input for Student b
    cin.getline(b.name, 100);  // Read the name
    cin >> b.roll >> b.gpa;    // Read roll and gpa

    // Output
    cout << a.name << " " << a.roll << " " << a.gpa << endl;
    cout << b.name << " " << b.roll << " " << b.gpa << endl;

    return 0;
}
