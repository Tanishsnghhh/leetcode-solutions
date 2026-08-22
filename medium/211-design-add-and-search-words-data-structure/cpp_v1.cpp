// Pushed: 2026-08-22 19:31:51 UTC
// Difficulty: Medium
// Runtime: 528 ms
// Memory: 649.2 MB

class WordDictionary {
public:
    class Node {
    public:
        int wordEnd;
        vector<Node*> childs;
        Node() {
            this->wordEnd = 0;
            this->childs.assign(26, nullptr);
        }
    };
    Node* root;
    WordDictionary() { root = new Node(); }

    void addWord(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int idx = ch - 'a';
            if (curr->childs[idx] == nullptr) {
                curr->childs[idx] = new Node();
            }
            curr = curr->childs[idx];
        }
        curr->wordEnd++;
    }

    bool solve(Node* node, int idx, string& word) {
        if (node == nullptr) {
            return false;
        }

        if (idx == word.size()) {
            return node->wordEnd != 0;
        }

        bool res = false;
        if (word[idx] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->childs[i] != nullptr) {
                    res = res || solve(node->childs[i], idx + 1, word);
                }
            }
        } else {
            int idx1 = word[idx] - 'a';
            if (node->childs[idx1] != nullptr) {
                res = res || solve(node->childs[idx1], idx + 1, word);
            }
        }
        return res;
    }

    bool search(string word) { return solve(root, 0, word); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */