#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>


class Trie {
private:
    struct TrieNode {
        std::unordered_map<char, TrieNode*> children;

        TrieNode() {}
    };

private:
    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}

    void insert(std::string word) {
        insertHelper(root, word);
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
            } else {
                curr->children[c] = new TrieNode();
                curr = curr->children[c];
            }
        } 
    }

    bool startsWithHelper(TrieNode* root, const std::string& word) {
        TrieNode* curr = root;
        for (const char c : word) {
            if (curr->children.find(c) == curr->children.end()) return false;
            curr = curr->children[c];
        }
        return true;
    }
};


class Solution {
public:
    int countPrefixSuffixPairs(std::vector<std::string>& words) {
        int count = 0;

        for (int i = 0; i < words.size(); i++) {
            Trie prefixTrie, suffixTrie;

            prefixTrie.insert(words[i]);
            std::string reversedWord = words[i];
            std::reverse(reversedWord.begin(), reversedWord.end());
            suffixTrie.insert(reversedWord);

            for (int j = 0; j < i; j++) {
                if (words[j].size() > words[i].size()) continue;
                reversedWord = words[j];
                std::reverse(reversedWord.begin(), reversedWord.end());
                if (prefixTrie.startsWith(words[j]) && suffixTrie.startsWith(reversedWord)) count++;
            }
        }

        return count;
    }
};