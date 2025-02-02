#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int elapsedTime = 0;  
    int unsatisfiedCustomers = 0;

    for (int i = 0; i < N; ++i) {
        int maxWaitTime, serviceTime;
        cin >> maxWaitTime >> serviceTime;

        int waitingTime = max(0, elapsedTime - i);

        if (waitingTime > maxWaitTime) 
        {
            unsatisfiedCustomers++;
        } 
        else 
        {
            elapsedTime = max(elapsedTime, i) + serviceTime;
        }
    }

    cout << unsatisfiedCustomers << endl;
    return 0;
}
