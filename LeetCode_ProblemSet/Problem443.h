//
// Created by HP on 4/13/2024.
//

#ifndef PROBLEM443_H
#define PROBLEM443_H
#include <vector>


class Solution {
    std::vector<char> getDigits(int x) {
        std::vector<char> answer;
        while(x >= 10) {
            answer.push_back(x % 10 + 48);
            x /= 10;
        }
        if(x % 10)
            answer.push_back(x % 10 + 48);
        return answer;
    }

public:
    int compress(std::vector<char>& chars) {
        std::vector<char> answer;
        int cnt = 1;
        for(int i = 0; i < chars.size(); i++) {
            while(i < chars.size() - 1 && chars[i] == chars[i+1]) {
                cnt++;
                i++;
            }
            answer.push_back(chars[i]);
            if(cnt == 1)
                continue;
            else if(cnt < 10)
                answer.push_back(cnt + 48);
            else {
                std::vector<char> digits = getDigits(cnt);
                for(int j = digits.size() - 1; j >= 0; j--)
                    answer.push_back(digits[j]);
            }
            cnt = 1;
        }
        chars = answer;
        return chars.size();
    }
};



#endif //PROBLEM443_H
