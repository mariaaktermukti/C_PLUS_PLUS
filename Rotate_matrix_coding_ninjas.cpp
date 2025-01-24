#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat, int n, int m) 
{
    if (n == 0 || m == 0) return;

    int top = 0, left = 0;
    int bottom = n - 1, right = m - 1;

    while (top < bottom && left < right) 
    {
        int prev = mat[top + 1][left];

        for (int i = left; i <= right; i++) 
        {
            int temp = mat[top][i];
            mat[top][i] = prev;
            prev = temp;
        }
        top++;

        for (int i = top; i <= bottom; i++) 
        {
            int temp = mat[i][right];
            mat[i][right] = prev;
            prev = temp;
        }
        right--;

        for (int i = right; i >= left; i--) 
        {
            int temp = mat[bottom][i];
            mat[bottom][i] = prev;
            prev = temp;
        }
        bottom--;

        for (int i = bottom; i >= top; i--) 
        {
            int temp = mat[i][left];
            mat[i][left] = prev;
            prev = temp;
        }
        left++;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) 
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                cin >> mat[i][j];
            }
        }

        rotateMatrix(mat, n, m);

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
