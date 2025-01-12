class Solution {
public:
    int minX = INT_MAX, minY = INT_MAX;
    int maxX = INT_MIN, maxY = INT_MIN;
    void dfs(int x, int y, vector<vector<char>>& image) {
        if(x < 0 || y < 0 || x >= image.size() || y >= image[0].size() || image[x][y] == '0') return;
        image[x][y] = '0';
        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
        dfs(x - 1, y, image);
        dfs(x + 1, y, image);
        dfs(x, y - 1, image);
        dfs(x, y + 1, image);
    }
    int minArea(vector<vector<char>>& image, int x, int y) {
        int rows = image.size();
        int cols = image[0].size();
        int area = 1;
        dfs(x, y, image);
        return area * (maxX - minX + 1) * (maxY - minY + 1);
    }
};
