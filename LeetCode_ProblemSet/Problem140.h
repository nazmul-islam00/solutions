//
// Created by HP on 5/25/2024.
//

#ifndef PROBLEM140_H
#define PROBLEM140_H
#include <string>
#include <unordered_map>
#include <vector>


class Solution {
private:
    void getSentences(std::string& s, std::unordered_map<std::string, int>& words, std::string& currSentence, std::vector<std::string>& result, int currIndex) {
        if(currIndex == s.size()) {
            result.push_back(currSentence);
            return;
        }
        for(int endIndex = currIndex + 1; endIndex <= s.size(); endIndex++) {
            std::string substr = s.substr(currIndex, endIndex - currIndex);
            if(words.find(substr) != words.end()) {
                std::string originalSentence = currSentence;
                if(currSentence.size() != 0) {
                    currSentence.append(" ");
                }
                currSentence.append(substr);
                getSentences(s, words, currSentence, result, endIndex);
                currSentence = originalSentence;
            }
        }

    }
public:
    std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_map<std::string, int> words;
        for(const auto& word : wordDict) {
            words[word] = 1;
        }
        std::vector<std::string> result;
        std::string currSentence;
        getSentences(s, words, currSentence, result, 0);
        return result;
    }
};



#endif //PROBLEM140_H
