/*
Complexity Analysis

Time Complexity: O(n * m)
Space Complexity: O(1)
*/
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X' and
                    (i == 0 or board[i - 1][j] != 'X') and
                    (j == 0 or board[i][j - 1] != 'X')) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
