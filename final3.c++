#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int cls;
    char section;
    int id;
};

int main() {
    int N;
    cin >> N; 
    cin.ignore(); 

    Student students[100]; 

    for (int i = 0; i < N; i++) {
        cin >> students[i].name >> students[i].cls >> students[i].section >> students[i].id;
    }

    for (int i = 0; i < N / 2; i++) {
        swap(students[i].section, students[N - i - 1].section);
    }

    for (int i = 0; i < N; i++) {
        cout << students[i].name << " " << students[i].cls << " " << students[i].section << " " << students[i].id << endl;
    }

    return 0;
}
