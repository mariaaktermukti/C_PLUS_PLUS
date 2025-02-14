#include <bits/stdc++.h>
using namespace std;

int n, m;
char maze[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int x, int y) 
{
    return (x >= 0 && x < n && y >= 0 && y < m && (maze[x][y] == '.' || maze[x][y] == 'D') && !vis[x][y]);
}

bool bfs(int sx, int sy, int dx, int dy) 
{
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;
    map<pair<int, int>, pair<int, int>> parent;
    parent[{sx, sy}] = {-1, -1};
    
    while (!q.empty()) 
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        
        if (x == dx && y == dy) 
        {
            while (parent[{x, y}] != make_pair(-1, -1)) 
            {
                auto p = parent[{x, y}];
                x = p.first;
                y = p.second;
                if (maze[x][y] != 'R') maze[x][y] = 'X';
            }
            return true;
        }
        
        for (auto move : moves) 
        {
            int nx = x + move.first;
            int ny = y + move.second;
            if (isValid(nx, ny)) 
            {
                q.push({nx, ny});
                vis[nx][ny] = true;
                parent[{nx, ny}] = {x, y};
            }
        }
    }
    return false;
}

int main() 
{
    cin >> n >> m;
    int sx, sy, dx, dy;
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'R') 
            {
                sx = i;
                sy = j;
            } 
            else if (maze[i][j] == 'D') 
            {
                dx = i;
                dy = j;
            }
        }
    }
    
    memset(vis, false, sizeof(vis));
    bfs(sx, sy, dx, dy);
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cout << maze[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
