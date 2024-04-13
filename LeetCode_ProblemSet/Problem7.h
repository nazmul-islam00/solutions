//
// Created by HP on 4/12/2024.
//

#ifndef PROBLEM7_H
#define PROBLEM7_H
#include <cmath>
#include <vector>


class Solution {
public:
    std::vector<int> get_digits(long x) {
        if(x < 0) {
            return get_digits(-x);
        }
        std::vector<int> answer;
        while(x>=10) {
            answer.push_back(x % 10);
            x /= 10;
        }
        answer.push_back(x);
        return answer;
    }

    int reverse(int x) {
        std::vector<int> digits = get_digits(x);
        long answer = 0;
        for(int i = 0; i < digits.size(); i++) {
            answer *= 10;
            answer += digits[i];
        }
        if(x < 0) {
            answer *= -1;
        }
        long ul = std::pow(2, 31) - 1;
        long ll = -std::pow(2, 31);
        if(ul >= answer && ll<= answer) {
            return answer;
        }
        return 0;
    }
};



#endif //PROBLEM7_H
