#include <string>
#include <vector>
#include <unordered_map>


class Solution {
public:
    std::vector<std::string> stringMatching(std::vector<std::string>& words) {
        std::vector<std::string> answer;
        answer.reserve(words.size());
        
        TrieNode* root = new TrieNode();
        for (const std::string& word : words) {
            for (int idx = 0; idx < word.size(); idx++) {
                insertWord(root, word.substr(idx));
            }
        }

        for (const std::string& word : words) {
            if (isSubstring(root, word)) {
                answer.push_back(word);
            }
        }

        return answer;
    }

private:
    struct TrieNode {
        int frequency;
        std::unordered_map<char, TrieNode*> childNodes;
    };

    void insertWord(TrieNode* root, const std::string& word) {
        TrieNode* currNode = root;

        for (const char c : word) {
            if (currNode->childNodes.find(c) != currNode->childNodes.end()) {
                currNode = currNode->childNodes[c];
                currNode->frequency++;
            } else {
                TrieNode* newNode = new TrieNode();
                newNode->frequency = 1;
                currNode->childNodes[c] = newNode;
                currNode = newNode;
            }
        }
    }

    bool isSubstring(TrieNode* root, const std::string& word) {
        TrieNode* currNode = root;
        for (const char c : word) {
            currNode = currNode->childNodes[c];
        }
        return currNode->frequency > 1;
    }
};