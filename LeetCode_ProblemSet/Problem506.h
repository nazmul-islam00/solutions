//
// Created by HP on 5/8/2024.
//

#ifndef PROBLEM506_H
#define PROBLEM506_H
#include <algorithm>
#include <string>
#include <vector>


class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        if(score.size() == 1) {
            return {"Gold Medal"};
        } else if(score.size() == 2) {
            if(score[0] > score[1]) {
                return {"Gold Medal", "Silver Medal"} ;
            } else {
                return {"Silver Medal", "Gold Medal"};
            }
        }
        std::vector<std::pair<int, int>> sortedScores;
        for(int i = 0; i < score.size(); i++) {
            sortedScores.push_back({score[i], i});
        }
        sort(sortedScores.begin(), sortedScores.end(), [](auto p1, auto p2) {
            return p1.first > p2.first;
        });
        std::vector<std::string> answer(score.size());
        for(int i = 0; i < sortedScores.size(); i++) {
            answer[sortedScores[i].second] = std::to_string(i + 1);
        }
        answer[sortedScores[0].second] = "Gold Medal";
        answer[sortedScores[1].second] = "Silver Medal";
        answer[sortedScores[2].second] = "Bronze Medal";
        return answer;
    }
};




#endif //PROBLEM506_H
