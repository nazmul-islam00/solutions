//
// Created by HP on 5/24/2024.
//

#ifndef PROBLEM1255_H
#define PROBLEM1255_H
#include <cmath>
#include <string>
#include <vector>


class Solution {
public:
    int maxScoreWords(std::vector<std::string>& words, std::vector<char>& letters, std::vector<int>& score) {
        // {score, count}
        std::vector<std::pair<int, int>> characters(26, {0, 0});
        for(char c : letters) {
            characters[c - 'a'].second++;
        }
        for(int i = 0; i < score.size(); i++) {
            characters[i].first = score[i];
        }
        int maxScore = 0;
        // iterate over all subsets
        for(int i = 0; i < std::pow(2, words.size()); i++) {
            std::vector<int> count(26, 0);
            bool isPossible = true;
            for(int j = 0; j < words.size() && isPossible; j++) {
                // if the word is in the subset
                if((1 << j) & i) {
                    for(int k = 0; k < words[j].size() && isPossible; k++) {
                        count[words[j][k] - 'a']++;
                        // if it doesn't exceed the given limit
                        isPossible = count[words[j][k] - 'a'] <= characters[words[j][k] - 'a'].second;
                    }
                }
            }
            int currScore = 0;
            if(isPossible) {
                for(int i = 0; i < count.size(); i++) {
                    currScore += count[i] * characters[i].first;
                }
                maxScore = std::max(maxScore, currScore);
            }
        }
        return maxScore;
    }
};



#endif //PROBLEM1255_H
