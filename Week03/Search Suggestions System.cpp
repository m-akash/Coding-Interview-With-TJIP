/*
Complexity Analysis
Time Complexity: 
Trie Construction: O(M×N), where M is the average product length, and N is the number of products.
Suggestion Retrieval: O(L×(P+3×26)), where L is the length of searchWord, P is the length of the prefix, and 3 is for finding up to 3 words per prefix.
Overall: O(M×N+L×P)

Space Complexity:
Trie Space: O(M×N), where M is the average word length and N is the number of products.
DFS Auxiliary Space: O(M), for the recursion stack, where M is the longest word length.
Product Suggestions Output: O(L×M), where L is the length of searchWord.
Overall: O(M×N) 
*/
class Solution {
public:
    class TrieNode {
    public:
        bool isEnd;
        TrieNode* next[26];
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
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
        void insert_word(string& word) {
            TrieNode* current = root;
            for (auto ch : word) {
                int id = ch - 'a';
                if (current->next[id] == nullptr) {
                    current->next[id] = new TrieNode();
                }
                current = current->next[id];
            }
            current->isEnd = true;
        }
    };

    Trie* initTrie(vector<string>& product) {
        Trie* trie = new Trie();
        for (auto pro : product) {
            trie->insert_word(pro);
        }
        return trie;
    }

    void dfs(TrieNode* u, string& current_word, vector<string>& result) {
        if (u == nullptr or result.size() == 3) {
            return;
        }
        if (u->isEnd) {
            result.push_back(current_word);
        }
        for (int i = 0; i < 26; i++) {
            if (u->next[i] == nullptr) {
                continue;
            }
            current_word.push_back((char)(i + 'a'));
            dfs(u->next[i], current_word, result);
            current_word.pop_back();
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie = initTrie(products);
        vector<vector<string>> suggestions;
        TrieNode* current_node = trie->root;
        string type_word;
        for (auto ch : searchWord) {
            type_word.push_back(ch);
            current_node = current_node ? current_node->next[ch - 'a'] : nullptr;
            vector<string> result;
            dfs(current_node, type_word, result);
            suggestions.push_back(result);
        }
        return suggestions;
    }
};
