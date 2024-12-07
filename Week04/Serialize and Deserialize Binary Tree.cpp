/*
Complexity Analysis

Time Complexity:
Space Compelxity:
*/
class Codec {
public:
    string seralize_helper(TreeNode* root) {
        if (root == nullptr) {
            return "#";
        }
        string left = seralize_helper(root->left);
        string right = seralize_helper(root->right);
        return to_string(root->val) + "," + left + "," + right;
    }

    string serialize(TreeNode* root) {
        return seralize_helper(root);
    }

    void populate_queue(string& data, queue<string>& q) {
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            q.push(token);
        }
    }

    TreeNode* deserialize_helper(queue<string>& q) {
        if (q.empty()) {
            return nullptr;
        }
        string u = q.front();
        q.pop();
        if (u == "#") {
            return nullptr;
        }
        TreeNode* current = new TreeNode(stoi(u));
        current->left = deserialize_helper(q);
        current->right = deserialize_helper(q);
        return current;
    }

    TreeNode* deserialize(string data) {
        queue<string> q;
        populate_queue(data, q);
        return deserialize_helper(q);
    }
};
