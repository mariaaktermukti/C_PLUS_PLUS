//area of component
#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];  
bool vis[1005][1005];   

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool isValid(int x, int y) 
{
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !vis[x][y]);
}

int bfs(int si, int sj) 
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    int area = 1;

    while (!q.empty()) 
    {
        pair<int, int> current = q.front();
        int x = current.first, y = current.second;
        q.pop();

        for (size_t i = 0; i < directions.size(); i++) 
        {
            int nx = x + directions[i].first;
            int ny = y + directions[i].second;
            if (isValid(nx, ny)) 
            {
                q.push({nx, ny});
                vis[nx][ny] = true;
                area++;
            }
        }
    }
    return area;
}

int main() 
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    int minArea = 100000;
    bool found = false;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (grid[i][j] == '.' && !vis[i][j]) 
            {
                int area = bfs(i, j);
                minArea = min(minArea, area);
                found = true;
            }
        }
    }

    if (!found) {
        cout << "-1" << endl;
    } else {
        cout << minArea << endl;
    }
    
    return 0;
}
