#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;
char grid[MAX_N][MAX_N];  
bool vis[MAX_N][MAX_N];   

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool isValid(int x, int y) 
{
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !vis[x][y]);
}

void bfs(int si, int sj) 
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

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
            }
        }
    }
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

    int Si, Sj, Di, Dj;
    cin >> Si >> Sj >> Di >> Dj;

    memset(vis, false, sizeof(vis));

    if (grid[Si][Sj] == '-' || grid[Di][Dj] == '-') 
    {
        cout << "NO" << endl;
        return 0;
    }

    bfs(Si, Sj);

    if (vis[Di][Dj]) 
    {
        cout << "YES" << endl;
    } 
    else 
    {
        cout << "NO" << endl;
    }

    return 0;
}
