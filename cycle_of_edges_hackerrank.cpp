#include <bits/stdc++.h>
using namespace std;

int par[100000 + 5];
int group_size[100000 + 5];

void dsu_init(int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = -1;
        group_size[i] = 1;
    }
}

int find(int node) {
    if (par[node] == -1)
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2) {
    int leader1 = find(node1);
    int leader2 = find(node2);
    if (leader1 != leader2) {
        if (group_size[leader1] >= group_size[leader2]) {
            par[leader2] = leader1;
            group_size[leader1] += group_size[leader2];
        } else {
            par[leader1] = leader2;
            group_size[leader2] += group_size[leader1];
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    dsu_init(n);

    int cycleCount = 0;
    vector<pair<int, int>> edges(m);

    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        int par_u = find(u);
        int par_v = find(v);

        if (par_u == par_v) {
            cycleCount++;
        } else {
            dsu_union(u, v);
        }
    }

    cout << cycleCount << endl;

    return 0;
}
