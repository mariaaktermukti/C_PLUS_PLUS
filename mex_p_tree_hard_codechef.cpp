#include <bits/stdc++.h>
#include <numeric>
#include <algorithm>
using namespace std;

static const vector<int> smallPrimes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

int f_val(int g) {
    for (int p : smallPrimes) {
        if(g % p != 0)
            return p;
    }
    return 2; 
}

using umap = unordered_map<int, long long>;

umap transform_dp(const umap &dp, int x) {
    umap ret;
    for (auto &pr : dp) {
        int newg = __gcd(pr.first, x);  
        ret[newg] += pr.second;
    }
    return ret;
}

umap merge_dp(const umap &a, const umap &b) {
    umap ret = a;
    for (auto &pr : b) {
        ret[pr.first] += pr.second;
    }
    return ret;
}

umap subtract_dp(const umap &a, const umap &b) {
    umap ret = a;
    for (auto &pr : b) {
        ret[pr.first] -= pr.second;
        if(ret[pr.first] == 0)
            ret.erase(pr.first);
    }
    return ret;
}
long long dp_sum(const umap &dp) {
    long long s = 0;
    for (auto &pr : dp) {
        s += (long long) f_val(pr.first) * pr.second;
    }
    return s;
}

const int NMAX = 200005;
vector<int> A;
vector<vector<int>> adj;
vector<umap> dpDown;      
vector<long long> S_down;  
vector<long long> ans;     

void dfs1(int u, int p) {
    dpDown[u].clear();
    dpDown[u][A[u]] = 1;              
    S_down[u] = f_val(A[u]);          
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        umap tmp = transform_dp(dpDown[v], A[u]);
        dpDown[u] = merge_dp(dpDown[u], tmp);
        S_down[u] += dp_sum(tmp);
    }
}
void dfs2(int u, int p, const umap &upMap) {
    umap tot = merge_dp(transform_dp(upMap, A[u]), dpDown[u]);
    ans[u] = dp_sum(tot);
    
    umap allChildren;
    for (int v : adj[u]) {
        if(v == p) continue;
        umap cur = transform_dp(dpDown[v], A[u]);
        allChildren = merge_dp(allChildren, cur);
    }
    
    for (int v : adj[u]) {
        if(v == p) continue;
        umap childContr = transform_dp(dpDown[v], A[u]);
        umap others = subtract_dp(allChildren, childContr);
        umap part = transform_dp(upMap, A[u]);
        umap newUp = merge_dp(part, others);
        newUp[A[u]] += 1; 
        dfs2(v, u, newUp);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        A.resize(n + 1);
        for (int i = 1; i <= n; i++){
            cin >> A[i];
        }
        adj.assign(n + 1, vector<int>());
        for (int i = 1; i <= n - 1; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        dpDown.assign(n + 1, umap());
        S_down.assign(n + 1, 0);
        ans.assign(n + 1, 0);
 
        dfs1(1, 0);
        umap emptyUp;
        emptyUp.clear();
        dfs2(1, 0, emptyUp);
 
        for (int i = 1; i <= n; i++){
            cout << ans[i] << (i == n ? "\n" : " ");
        }
    }
    return 0;
}
