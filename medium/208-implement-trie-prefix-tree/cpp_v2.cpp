// Pushed: 2026-08-23 12:10:47 UTC
// Difficulty: Medium
// Runtime: 11 ms
// Memory: 50.4 MB

class TrieNode {
public:
    bool isEnd;             // Word yahan end hota hai ya nahi
    TrieNode* children[26];     //// Next 26 letters ke Nodes store honge
    TrieNode() {
        isEnd = false;              // Starting mein koi word end nahi hai
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;            // Starting mein koi child Node nahi hai
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:

    Trie() { 
        root = new TrieNode();              // Starting mein ek empty root Node banao
    }

    void insert(string str) {

        TrieNode* curr = root;              // Word insert karna root se start karo

        for (int i = 0; i < str.length(); i++) {

            char ch = str[i];               // Current character nikalo

            int idx = ch - 'a';             // Character ko 0-25 index mein convert karo

            if (curr->children[idx] == nullptr) {

                curr->children[idx] = new TrieNode(); 
                                             // Agar character ka Node nahi hai,
                                             // toh naya Node banao
            }

            curr = curr->children[idx];     // Ab current Node ko is character ke
                                            // Node par move karo
        }

        curr->isEnd = true;                 // Last character par word complete mark karo
    }    bool search(string str) {

        TrieNode* curr = root;              // Search root se start karo

        for (int i = 0; i < str.length(); i++) {

            char ch = str[i];               // Current character nikalo

            int idx = ch - 'a';             // Character ko 0-25 index mein convert karo

            if (curr->children[idx] == nullptr) {

                return false;               // Character nahi mila → word exist nahi karta
            }

            curr = curr->children[idx];     // Next character ke Node par move karo
        }

        return curr->isEnd;                 // Pura word mila → check karo word yahin end hota hai
    }


    bool startsWith(string str) {

        TrieNode* curr = root;              // Prefix search bhi root se start karo

        for (int i = 0; i < str.length(); i++) {

            char ch = str[i];               // Current character nikalo

            int idx = ch - 'a';             // Character ko 0-25 index mein convert karo

            if (curr->children[idx] == nullptr) {

                return false;               // Character nahi mila → koi word is prefix se start nahi hota
            }

            curr = curr->children[idx];     // Next character ke Node par move karo
        }

        return true;                        // Pura prefix mil gaya → prefix exist karta hai
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */