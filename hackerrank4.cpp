#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Student {
    int id;
    string name;
    char section;
    int totalMarks;
};

int main() {
    int T; 
    cin >> T;

    while (T--) {
        Student students[3]; 

        for (int i = 0; i < 3; i++) {
            cin >> students[i].id >> students[i].name >> students[i].section >> students[i].totalMarks;
        }

        Student bestStudent = {std::numeric_limits<int>::max(), "", ' ', -1};

        for (int i = 0; i < 3; i++) {
            if (students[i].totalMarks > bestStudent.totalMarks) {
                bestStudent = students[i]; 
            } else if (students[i].totalMarks == bestStudent.totalMarks && students[i].id < bestStudent.id) {
                bestStudent = students[i]; 
            }
        }

        cout << bestStudent.id << " " << bestStudent.name << " " << bestStudent.section << " " << bestStudent.totalMarks << endl;
    }

    return 0;
}
