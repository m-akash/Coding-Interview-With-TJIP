/*
Complexity Analysis

Time Complexity: O(N)
Space Complexity: O(N)
*/
class Solution {
public:
    vector<int> dir = {-1, 0, +1, 0, -1};
    unordered_map<int, bool> visited;

    void moveBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    void clean(Robot& robot, int x, int y, int currDir) {
        robot.clean();
        visited[(x * 1000) + y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[currDir];
            int ny = y + dir[currDir + 1];
            if (visited.count((nx * 1000) + ny) == 0 && robot.move()) {
                clean(robot, nx, ny, currDir);
                moveBack(robot);
            }
            robot.turnRight();
            currDir = (currDir + 1) % 4;
        }
    }
    
    void cleanRoom(Robot& robot) {
        clean(robot, 0, 0, 0);
    }
};
