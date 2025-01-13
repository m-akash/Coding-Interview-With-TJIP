/*
Complexity Analysis

Time Complexity: O (V + P) where V is the number of courses and P is the number of prerequisites.
Space Complexity: O (V + P)
*/
class Solution {
public:
    vector<int> color;
    vector<vector<int>> graph;
    bool hasCycle(int u) {
        color[u] = 1;
        for (auto& v : graph[u]) {
            if (color[v] == 0 and hasCycle(v)) {
                return true;
            } else if (color[v] == 1) {
                return true;
            }
        }
        color[u] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        color.clear();
        graph.clear();
        color.resize(numCourses, 0);
        graph.resize(numCourses);
        for (auto& edges : prerequisites) {
            graph[edges[1]].push_back(edges[0]);
        }
        for (int u = 0; u < numCourses; u++) {
            if (color[u] == 0 and hasCycle(u)) {
                return false;
            }
        }
        return true;
    }
};
