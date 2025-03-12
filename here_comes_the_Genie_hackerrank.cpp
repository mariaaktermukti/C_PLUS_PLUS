#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;

    vector<long long> a(n);

    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<long long>());

    long long current_max = 1000000000LL + 1;
    long long total = 0;

    for(int i=0; i<n; i++)
    {
        long long choosen = min(a[i], current_max - 1);

        if(choosen < 0)
        {
            choosen = 0;
        }
        total = total + choosen;
        current_max = choosen;

        if(current_max == 0)
           break;

    }
    cout << total;
    return 0;
}
