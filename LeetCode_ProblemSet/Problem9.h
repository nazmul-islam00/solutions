//
// Created by HP on 5/3/2024.
//

#ifndef PROBLEM9_H
#define PROBLEM9_H
#include <vector>


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        std::vector<long long> digits;
        long long temp = x;
        while (temp >= 1) {
            digits.push_back(temp % 10);
            temp /= 10;
        }
        long long res = 0;
        for (int i = 0; i <= digits.size() - 1; i++) {
            res *= 10;
            res += digits[i];
        }
        if (x == res)
            return true;
        return false;
    }
};



#endif //PROBLEM9_H
