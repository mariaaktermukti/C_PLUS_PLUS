//count apartment
#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool vis[1001][1001];

vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int row, col;

bool valid(int x, int y) 
{
    return x >= 0 && x < row && y >= 0 && y < col && graph[x][y] == '.' && !vis[x][y];
}

void dfs(int sr, int sc) 
{
    vis[sr][sc] = true;
    for (int i = 0; i < 4; i++) 
    {
        int child_row = sr + direction[i].first;
        int child_col = sc + direction[i].second;
        if (valid(child_row, child_col)) 
        {
            dfs(child_row, child_col);
        }
    }
}

int main() 
{
    cin >> row >> col;
    
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            cin >> graph[i][j];
        }
    }
    
    memset(vis, false, sizeof(vis));
    int apartment_count = 0;
    
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            if (graph[i][j] == '.' && !vis[i][j]) 
            {
                dfs(i, j);
                apartment_count++;
            }
        }
    }
    
    cout << apartment_count << endl;
    
    return 0;
}
