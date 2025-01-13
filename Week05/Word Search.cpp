/*
Complexity Analysis

Time Complexity: O(M * N (4^L)), Where M and N is the Number of cells in the given board, and L is the length of the word.
Space Complexity: O(L).  
*/
class Solution {
public:
    int ROW;
    int COL;
    bool dfs(vector<vector<char>>& board, string word, int row, int col, int cur_indx) {
        if (cur_indx == word.size()) {
            return true;
        }
        if (row < 0 or col < 0 or row >= ROW or col >= COL or
            board[row][col] != word[cur_indx] or board[row][col] == '#') {
            return false;
        }
        board[row][col] = '#';
        bool result = dfs(board, word, row + 1, col, cur_indx + 1) or
                      dfs(board, word, row, col + 1, cur_indx + 1) or
                      dfs(board, word, row - 1, col, cur_indx + 1) or
                      dfs(board, word, row, col - 1, cur_indx + 1);
        board[row][col] = word[cur_indx];
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        ROW = board.size();
        COL = board[0].size();
        for (int row = 0; row < ROW; row++) {
            for (int col = 0; col < COL; col++) {
                if (dfs(board, word, row, col, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
