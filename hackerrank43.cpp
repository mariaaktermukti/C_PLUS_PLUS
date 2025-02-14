#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

bool isValid(int x, int y, int n, int m, vector<vector<bool>> &vis) 
{
    return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]);
}

int bfs(int n, int m, int sx, int sy, int dx, int dy) 
{
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> level(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;
    level[sx][sy] = 0;

    while (!q.empty()) 
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        if (x == dx && y == dy) 
        {
            return level[x][y];
        }

        for (auto move : moves) 
        {
            int nx = x + move.first;
            int ny = y + move.second;
            if (isValid(nx, ny, n, m, vis)) 
            {
                q.push({nx, ny});
                vis[nx][ny] = true;
                level[nx][ny] = level[x][y] + 1;
            }
        }
    }
    return -1;
}

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n, m, sx, sy, dx, dy;
        cin >> n >> m;
        cin >> sx >> sy;
        cin >> dx >> dy;
        cout << bfs(n, m, sx, sy, dx, dy) << endl;
    }
    return 0;
}
