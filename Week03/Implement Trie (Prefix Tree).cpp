class Trie {
public:
    class TrieNode {
    public:
        char ch;
        bool mark = false;
        unordered_map<char, TrieNode*> next;
    };
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        auto current = root;
        for (auto& ch : word) {
            if (current->next[ch] == nullptr) {
                current->next[ch] = new TrieNode();
            }
            current = current->next[ch];
        }
        current->mark = true;
    }

    bool search(string word, bool is_prefix_search = false) {
        auto current = root;
        for (auto& ch : word) {
            if (current->next[ch] == nullptr) {
                return false;
            }
            current = current->next[ch];
        }
        return is_prefix_search or (current and current->mark);
    }

    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};
