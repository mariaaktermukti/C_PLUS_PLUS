#include <iostream>
#include <set>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

struct StudentComparator {
    bool operator()(const tuple<string, int, int>& a, const tuple<string, int, int>& b) const 
    {
        if (get<2>(a) != get<2>(b)) return get<2>(a) > get<2>(b); 
        if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b); 
        return get<0>(a) < get<0>(b); 
    }
};

int main() 
{
    int n;
    cin >> n;
    set<tuple<string, int, int>, StudentComparator> studentSet;

    for (int i = 0; i < n; ++i) 
    {
        string name;
        int age, marks;
        cin >> name >> age >> marks;
        studentSet.emplace(name, age, marks);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) 
    {
        int command;
        cin >> command;

        if (command == 1) 
        {
            if (!studentSet.empty()) 
            {
                auto maxStudent = *studentSet.begin();
                cout << get<0>(maxStudent) << " " << get<1>(maxStudent) << " " << get<2>(maxStudent) << endl;
            } 
            else 
            {
                cout << "Empty" << endl;
            }
        } 
        else if (command == 2) 
        {
            if (!studentSet.empty()) 
            {
                studentSet.erase(studentSet.begin());
                if (!studentSet.empty()) 
                {
                    auto maxStudent = *studentSet.begin();
                    cout << get<0>(maxStudent) << " " << get<1>(maxStudent) << " " << get<2>(maxStudent) << endl;
                } 
                else 
                {
                    cout << "Empty" << endl;
                }
            } 
            else 
            {
                cout << "Empty" << endl;
            }
        } 
        else if (command == 0) 
        {
            string name;
            int age, marks;
            cin >> name >> age >> marks;
            studentSet.emplace(name, age, marks);
            auto maxStudent = *studentSet.begin();
            cout << get<0>(maxStudent) << " " << get<1>(maxStudent) << " " << get<2>(maxStudent) << endl;
        }
    }

    return 0;
}
