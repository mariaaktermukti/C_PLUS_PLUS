#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void solve() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;                      
        cin >> N >> M;
        vector<string> grid(N);
        for (int i = 0; i < N; ++i) {
            cin >> grid[i];
        }

        auto isValid = [&](int x, int y) {
            return x >= 0 && x < N && y >= 0 && y < M && grid[x][y] == '.';
        };

        vector<vector<bool>> visited(N, vector<bool>(M, false));
        queue<pair<int, int>> q; // (x, y)
        q.push({0, 0});
        visited[0][0] = true;

        int steps = 0;
        bool reached = false;

        while (!q.empty() && !reached) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();

                if (x == N - 1 && y == M - 1) {
                    reached = true;
                    cout << steps << "\n";
                    break;
                }

                for (int d = 0; d < 4; ++d) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (isValid(nx, ny) && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            ++steps;
        }

        if (!reached) {
            cout << -1 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
