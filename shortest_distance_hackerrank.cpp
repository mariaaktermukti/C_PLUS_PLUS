#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, E;
    cin >> N >> E;
    
    // Use a large constant for infinity.
    const long long INF = 1000000000000000000LL;
    
    // Create a distance matrix (1-indexed).
    vector<vector<long long>> dist(N + 1, vector<long long>(N + 1, INF));
    
    // Distance from any node to itself is 0.
    for (int i = 1; i <= N; i++){
        dist[i][i] = 0;
    }
    
    // Read the edges. For multiple edges, store only the minimum weight.
    for (int i = 0; i < E; i++){
        int A, B, W;
        cin >> A >> B >> W;
        dist[A][B] = min(dist[A][B], (long long)W);
    }
    
    // Floyd-Warshall algorithm to compute all-pairs shortest paths.
    for (int k = 1; k <= N; k++){
        for (int i = 1; i <= N; i++){
            if (dist[i][k] == INF) continue;
            for (int j = 1; j <= N; j++){
                if (dist[k][j] == INF) continue;
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    
    int Q;
    cin >> Q;
    while (Q--){
        int X, Y;
        cin >> X >> Y;
        if (X < 1 || X > N || Y < 1 || Y > N || dist[X][Y] == INF)
            cout << -1 << "\n";
        else
            cout << dist[X][Y] << "\n";
    }
    
    return 0;
}
