/*
Complexity Analysis

Time Complexity: O(M * N)
Space Complexity: O(M * N)
*/
class Solution {
public:
    constexpr static array<int, 5> dirs = {-1, 0, 1, 0, -1};
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> Q;
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[i].size(); j++) {
                if (rooms[i][j] == 0) {
                    Q.push({i, j});
                }
            }
        }
        while (!Q.empty()) {
            auto u = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int ux = u.first + dirs[i];
                int uy = u.second + dirs[i + 1];
                if (ux < 0 || uy < 0 || ux >= rooms.size() || uy >= rooms[0].size()) {
                    continue;
                }
                if (rooms[ux][uy] == INT_MAX) {
                    rooms[ux][uy] = rooms[u.first][u.second] + 1;
                    Q.push({ux, uy});
                }
            }
        }
    }
};
