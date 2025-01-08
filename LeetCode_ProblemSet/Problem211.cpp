#include <unordered_map>
#include <string>


class WordDictionary {
private:
    struct TrieNode {
        bool isLast;
        std::unordered_map<char, TrieNode*> children;

        TrieNode() : isLast(false) {}
    };

private:
    TrieNode* root;

public:
    WordDictionary() : root(new TrieNode()) {}

    void addWord(std::string word) {
        addWordHelper(root, word);
    }

    bool search(std::string word) {
        return searchHelper(root, word, 0);
    }

private:
    void addWordHelper(TrieNode* root, const std::string& word) {
        TrieNode* curr = root;

        for (const char c : word) {
            if (curr->children.find(c) != curr->children.end()) {
                curr = curr->children[c];
            } else {
                curr->children[c] = new TrieNode();
                curr = curr->children[c];
            }
        }

        curr->isLast = true;
    }

    bool searchHelper(TrieNode* curr, const std::string& word, int idx) {
        if (idx == word.size()) return curr->isLast;
        if (curr->children.size() == 0) return false;

        if (word[idx] != '.' && curr->children.find(word[idx]) == curr->children.end()) {
            return false;
        }
        if (word[idx] != '.') {
            return searchHelper(curr->children[word[idx]], word, idx + 1);
        }
        
        for (const std::pair<char, TrieNode*>& pair : curr->children) {
            if (searchHelper(pair.second, word, idx + 1)) return true;
        }
        
        return false;
    }
};