/*
Complexity Analysis
Time Complexity: O(V.logN)
Space Complexity: O(V)
*/
class Solution {  
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        map<int, vector<int>>values;
        queue<pair<TreeNode*, int>>Q;
        Q.push({root, 0});
        while(!Q.empty()){
            auto [u, cand] = Q.front();
            Q.pop();
            values[cand].push_back(u->val);
            if(u->left != nullptr) { 
                Q.push({u->left, cand - 1});
            }
            if(u->right != nullptr) { 
                Q.push({u->right, cand + 1});
            }
        }
        vector<vector<int>>ans;
        for(auto &it:values) { 
            ans.push_back(it.second);
        }
        return ans;
    }
};
