#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
    std::vector<std::string> getWords(const std::string& sentence) {
        std::stringstream ss(sentence);
        std::vector<std::string> words;
        words.reserve(100);
        std::string word;
        while (ss >> word) {
            words.emplace_back(word);
        }
        return words;
    }

    std::string removeSpaces(const std::vector<std::string>& words) {
        std::string result = "";
        for (const std::string& word : words) {
            result += word;
        }
        return result;
    }

public:
    bool areSentencesSimilar(std::string sentence1, std::string sentence2) {
        if (sentence1 == sentence2) {
            return true;
        }

        std::vector<std::string> words1 = this->getWords(sentence1);
        std::vector<std::string> words2 = this->getWords(sentence2);

        std::string _sentence1 = this->removeSpaces(words1);
        std::string _sentence2 = this->removeSpaces(words2);

        std::string longestCommonPrefix = "";
        std::string longestCommonSuffix = "";

        int prefixLen = -1;
        for (int i = 0; i < std::min(words1.size(), words2.size()); i++) {
            if (words1[i] != words2[i]) {
                prefixLen = i;
                break;
            }
            longestCommonPrefix += words1[i];
        }
        
        if (prefixLen != -1) {
            words1.erase(words1.begin(), words1.begin() + prefixLen);
            words2.erase(words2.begin(), words2.begin() + prefixLen);
        }

        for (int i = 0; i < std::min(words1.size(), words2.size()); i++) {
            if (words1[words1.size() - i - 1] != words2[words2.size() - i - 1]) {
                break;
            }
            longestCommonSuffix = words1[words1.size() - i - 1] + longestCommonSuffix;
        }

        std::string sentence = longestCommonPrefix + longestCommonSuffix;

        if (
            longestCommonPrefix == _sentence1 ||
            longestCommonPrefix == _sentence2 ||
            longestCommonSuffix == _sentence1 ||
            longestCommonSuffix == _sentence2 ||
            sentence == _sentence1 ||
            sentence == _sentence2
        ) {
            return true;
        }
        return false;
    }
};