//
// Created by HP on 6/1/2024.
//

#ifndef PROBLEM3110_H
#define PROBLEM3110_H
#include <cmath>
#include <string>


class Solution {
public:
    int scoreOfString(std::string s) {
        int score = 0;
        for(int i = 0; i < s.size( ) - 1; i++) {
            score += std::abs(s[i] - s[i + 1]);
        }
        return score;
    }
};



#endif //PROBLEM3110_H
