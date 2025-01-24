#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) 
{
    int M = mat.size();
    int N = mat[0].size();
    
    int row = 0;
    int col = N - 1;
    
    while (row < M && col >= 0) 
    {
        if (mat[row][col] == target) 
        {
            return true;
        } 
        else if (mat[row][col] > target) 
        {
            col--;
        } 
        else 
        {
            row++;
        }
    }
    
    return false;
}

int main() {
    int M, N, target;
    cin >> M >> N >> target;

    vector<vector<int>> mat(M, vector<int>(N));
    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cin >> mat[i][j];
        }
    }

    if (searchMatrix(mat, target)) 
    {
        cout << "true" << endl;
    } 
    else 
    {
        cout << "false" << endl;
    }

    return 0;
}
