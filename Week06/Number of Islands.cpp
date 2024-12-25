/*
Complexity Analysis

Time Complexity: O (m * n)
Space Complexity: O (m * n)
*/
class Solution {
public:
    int n, m;
    void dfs(vector<vector<char>>& grid, int row, int col) {
        m = grid.size();
        n = grid[0].size();
        if (row < 0 or col < 0 or row >= m or col >= n or
            grid[row][col] == '0') {
            return;
        }
        grid[row][col] = '0';
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    island++;
                    dfs(grid, i, j);
                }
            }
        }
        return island;
    }
};
