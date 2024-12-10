/*
Complexity Analysis
Time Complexity: O(M * N * 4 * 3^t-1 + S)
Here, M is the number of rows and N is the number of columns, t is the maximum length of any 'word' in the array words and S is the sum of the lengths of all the words.
Space Complexity: O(S).
*/
class Solution {
    unordered_set<string> res;
    vector<vector<bool>> visit;
public:
    class TrieNode {
    public:
        bool isEnd;
        unordered_map<char, TrieNode*> next;
        TrieNode() {
            isEnd = false;
        }
        void insert_word(string& words) {
            TrieNode* current = this;
            for (auto ch : words) {
                if (current->next[ch] == nullptr) {
                    current->next[ch] = new TrieNode();
                }
                current = current->next[ch];
            }
            current->isEnd = true;
        }
    };

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, string word) {
        int rows = board.size();
        int col = board[0].size();
        if (r < 0 || c < 0 || r >= rows || c >= col || visit[r][c] ||
            node->next[board[r][c]] == nullptr) {
            return;
        }
        visit[r][c] = true;
        node = node->next[board[r][c]];
        word = word + board[r][c];
        if (node->isEnd) {
            res.insert(word);
        }
        dfs(board, r + 1, c, node, word);
        dfs(board, r - 1, c, node, word);
        dfs(board, r, c + 1, node, word);
        dfs(board, r, c - 1, node, word);
        visit[r][c] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (auto& word : words) {
            root->insert_word(word);
        }
        int row = board.size(), col = board[0].size();
        visit.assign(row, vector<bool>(col, false));
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                dfs(board, r, c, root, "");
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};
