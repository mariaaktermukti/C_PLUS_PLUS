#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        long long N, C;
        cin >> N >> C;
        string S;
        cin >> S;

        vector<long long> freq(5, 0LL);
        for(char ch : S) {
            freq[ch - 'A']++;
        }

        long long ans = LLONG_MAX;
        for(int mask = 0; mask < 32; mask++){
            long long coverage = 0;  
            int learnedCount = 0;    

            for(int i = 0; i < 5; i++){
                if(mask & (1 << i)){
                    coverage += freq[i];
                    learnedCount++;
                }
            }
            long long notCovered = N - coverage;
            long long translatorCost = notCovered * (notCovered + 1) / 2;

            long long totalCost = learnedCount * C + translatorCost;

            ans = min(ans, totalCost);
        }

        cout << ans << "\n";
    }

    return 0;
}
