#include <iostream>
#include <vector>
#include <limits>
#include <utility>

using namespace std;

struct Edge {
    int u, v, w;
};

void bellmanFord(int N, int S, const vector<Edge>& edges, vector<int>& dist) {
    dist.assign(N + 1, numeric_limits<int>::max());
    dist[S] = 0;

    for (int i = 1; i <= N - 1; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != numeric_limits<int>::max() && dist[edge.u] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }

    for (const auto& edge : edges) {
        if (dist[edge.u] != numeric_limits<int>::max() && dist[edge.u] + edge.w < dist[edge.v]) {
            cout << "Negative Cycle Detected" << endl;
            exit(0);
        }
    }
}

int main() {
    int N, E;
    cin >> N >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int S;
    cin >> S;

    int T;
    cin >> T;

    vector<int> testCases(T);
    for (int i = 0; i < T; ++i) {
        cin >> testCases[i];
    }

    vector<int> dist;
    bellmanFord(N, S, edges, dist);

    for (int i = 0; i < T; ++i) {
        int D = testCases[i];
        if (dist[D] == numeric_limits<int>::max()) {
            cout << "Not Possible" << endl;
        } else {
            cout << dist[D] << endl;
        }
    }

    return 0;
}
