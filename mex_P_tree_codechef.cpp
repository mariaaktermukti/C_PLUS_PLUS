#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
                      31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
                      73, 79, 83, 89, 97};
 
int N;
vector<ll> A;
vector<vector<int>> adj;
vector<ll> B;  
 
void dfs(int s, int u, int par, ll g) {
    g = __gcd(g, A[u]);

    int f_val = 0;
    for (int p : primes) {
        if(g % p != 0) { 
            f_val = p;
            break;
        }
    }
    B[s] += f_val;

    for (int v : adj[u]) {
        if(v == par) continue;
        dfs(s, v, u, g);
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--){
        cin >> N;
        A.resize(N+1);
        for (int i = 1; i <= N; i++){
            cin >> A[i];
        }
        
        adj.assign(N+1, vector<int>());
        for (int i = 1; i < N; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        B.assign(N+1, 0);
        
        for (int i = 1; i <= N; i++){
            dfs(i, i, 0, A[i]);
        }
 
        for (int i = 1; i <= N; i++){
            cout << B[i] << (i == N ? "\n" : " ");
        }
    }
    return 0;
}
