class Solution {
public:
    class TrieNode {
    public:
        TrieNode* next[2];
        TrieNode() {
            for (int i = 0; i < 2; i++) {
                next[i] = nullptr;
            }
        }
    };

    class Trie {
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }

        bool check_bit(int num, int pos) {
            int state = num & (1 << pos);
            return state > 0 ? 1 : 0;
        }

        void insert(int num) {
            auto current = root;
            for (int pos = 30; pos >= 0; pos--) {
                int current_bit = check_bit(num, pos);
                if (current->next[current_bit] == nullptr) {
                    current->next[current_bit] = new TrieNode();
                }
                current = current->next[current_bit];
            }
        }

        int best_match_pair(int num) {
            auto current = root;
            int best_match = 0;
            for (int pos = 30; pos >= 0; pos--) {
                int current_bit = check_bit(num, pos);
                int opposite_bit = current_bit ^ 1;
                if (current->next[opposite_bit]) {
                    best_match = best_match | (1 << pos);
                    current = current->next[opposite_bit];
                } else {
                    current = current->next[current_bit];
                }
            }
            return best_match;
        }
    };

    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        trie->insert(nums[0]);
        int max_xor = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int current = nums[i];
            int best_match = trie->best_match_pair(current);
            max_xor = max(max_xor, best_match);
            trie->insert(current);
        }
        return max_xor;
    }
};
