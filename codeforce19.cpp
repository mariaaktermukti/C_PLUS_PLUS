#include <iostream>
using namespace std;

char grid[100][100];

// Recursive function to fill the sub-grid
void fillGrid(int r, int c, int r1, int c1, int r2, int c2, char ch) {
    // Base case: If the current position is out of bounds for the sub-grid
    if (r > r2 || c > c2) {
        return;
    }

    // Fill the current cell
    grid[r][c] = ch;

    // Move to the next column in the same row
    if (c < c2) {
        fillGrid(r, c + 1, r1, c1, r2, c2, ch);
    }
    // Move to the next row and reset the column to the starting column
    else if (r < r2) {
        fillGrid(r + 1, c1, r1, c1, r2, c2, ch);
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    // Initialize the grid with dots
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = '.';
        }
    }

    // Process instructions
    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        char c;
        cin >> r1 >> c1 >> r2 >> c2 >> c;

        // Convert to 0-based indexing
        r1--;
        c1--;
        r2--;
        c2--;

        // Use recursion to fill the sub-grid
        fillGrid(r1, c1, r1, c1, r2, c2, c);
    }

    // Print the final grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
