#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Query
{
private:
    unordered_map<long long, long long> freq;  
    priority_queue<pair<long long, long long>> pq;
    
public:
    void processQueries() 
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int Q;
        cin >> Q;
        
        while(Q--) 
        {
            int type;
            cin >> type;
            
            if(type == 1) 
            {
                long long x;
                cin >> x;
                freq[x]++;
                pq.push({freq[x], x});
            } 
            else
            {
                while(!pq.empty() && freq[pq.top().second] != pq.top().first) 
                {
                    pq.pop();
                }
                if(pq.empty())
                {
                    cout << "empty" << "\n";
                } 
                else 
                {
                    auto topPair = pq.top();
                    pq.pop();
                    long long currentFreq = topPair.first;
                    long long currentVal = topPair.second;
                    cout << currentVal << "\n";
                    
                    long long removeCount = max(1LL, currentFreq / 2);
                    freq[currentVal] -= removeCount;
                    if(freq[currentVal] > 0) 
                    {
                        pq.push({freq[currentVal], currentVal});
                    } 
                    else 
                    {
                        freq.erase(currentVal);
                    }
                }
            }
        }
    }
};

int main(){
    Query q;
    q.processQueries();
    return 0;
}
