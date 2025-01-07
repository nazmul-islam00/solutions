#include <unordered_map>
#include <string>


class Trie {
private:
    struct TrieNode {
        int frequency;
        bool isLast;
        std::unordered_map<char, TrieNode*> children;

        TrieNode() : frequency(1), isLast(false) {}
    };

private:
    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}

    void insert(std::string word) {
        insertHelper(root, word);
    }

    bool search(std::string word) {
        return searchHelper(root, word);
    }

    bool startsWith(std::string prefix) {
        return startsWithHelper(root, prefix);
    }

private:
    void insertHelper(TrieNode* root, const std::string& word) {
        TrieNode* curr = root;

        for (const char c : word) {
            if (curr->children.find(c) != curr->children.end()) {
                curr = curr->children[c];
                curr->frequency++;
            } else {
                curr->children[c] = new TrieNode();
                curr = curr->children[c];
            }
        } 

        curr->isLast = true;
    }

    TrieNode* getLastTrieNode(TrieNode* root, const std::string& word) {
        TrieNode* curr = root;
        for (const char c : word) {
            if (curr->children.find(c) == curr->children.end()) return nullptr;
            curr = curr->children[c];
        }
        return curr;
    }

    bool searchHelper(TrieNode* root, const std::string& word) {
        TrieNode* lastTrieNode = getLastTrieNode(root, word);
        return lastTrieNode != nullptr && lastTrieNode->isLast;
    }

    bool startsWithHelper(TrieNode* root, const std::string& word) {
        return getLastTrieNode(root, word) != nullptr;
    }
};