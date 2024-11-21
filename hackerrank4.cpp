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
    int T; // Number of test cases
    cin >> T;

    // Iterate through each test case
    while (T--) {
        Student students[3]; // Array to hold data for 3 students

        // Read input for 3 students
        for (int i = 0; i < 3; i++) {
            cin >> students[i].id >> students[i].name >> students[i].section >> students[i].totalMarks;
        }

        // Initialize the "best student" with impossible values
        Student bestStudent = {std::numeric_limits<int>::max(), "", ' ', -1};

        // Find the best student
        for (int i = 0; i < 3; i++) {
            if (students[i].totalMarks > bestStudent.totalMarks) {
                bestStudent = students[i]; // Update if higher marks
            } else if (students[i].totalMarks == bestStudent.totalMarks && students[i].id < bestStudent.id) {
                bestStudent = students[i]; // Update if same marks but smaller ID
            }
        }

        // Print the best student's details
        cout << bestStudent.id << " " << bestStudent.name << " " << bestStudent.section << " " << bestStudent.totalMarks << endl;
    }

    return 0;
}
