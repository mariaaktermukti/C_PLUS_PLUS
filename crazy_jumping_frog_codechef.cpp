#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void union_sets(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x != root_y) {
            if (size[root_x] < size[root_y]) {
                swap(root_x, root_y);
            }
            parent[root_y] = root_x;
            size[root_x] += size[root_y];
        }
    }

    int get_size(int x) {
        return size[find(x)];
    }
};

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        // Sort frogs by their initial positions
        vector<pair<int, int>> sorted_positions(N);
        for (int i = 0; i < N; ++i) {
            sorted_positions[i] = {A[i], i};
        }
        sort(sorted_positions.begin(), sorted_positions.end());

        // DSU setup
        DSU dsu(2 * N + 1);
        vector<bool> visited(2 * N + 1, false);
        int max_group_size = 0;

        for (const auto &pair : sorted_positions) {
            int pos = pair.first;
            int i = pair.second;
            visited[pos] = true;
            
            // Union with left and right neighbors if visited
            if (pos > 1 && visited[pos - 1]) {
                dsu.union_sets(pos, pos - 1);
            }
            if (pos < 2 * N && visited[pos + 1]) {
                dsu.union_sets(pos, pos + 1);
            }

            max_group_size = max(max_group_size, dsu.get_size(pos));
        }

        cout << max_group_size << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
