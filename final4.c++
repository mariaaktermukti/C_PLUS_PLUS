#include <bits/stdc++.h>
using namespace std;

struct Student {
    string nm;
    int cls;
    char s;
    int id;
    int math_marks;
    int eng_marks;

    int totalMarks() const {
        return math_marks + eng_marks;
    }
};

bool compare(const Student &a, const Student &b) {
    if (a.totalMarks() != b.totalMarks())
        return a.totalMarks() > b.totalMarks(); 
    return a.id < b.id; 
}


int main() {
    int N;
    cin >> N;
    cin.ignore();

    Student students[100];

    for (int i = 0; i < N; i++) {
        cin >> students[i].nm >> students[i].cls >> students[i].s >> 
             students[i].id >> students[i].math_marks >> students[i].eng_marks;
    }

    sort(students, students + N, compare);

    for (int i = 0; i < N; i++) {
        cout << students[i].nm << " " << students[i].cls << " " << students[i].s << " "
             << students[i].id << " " << students[i].math_marks << " " << students[i].eng_marks << endl;
    }

    return 0;
}
