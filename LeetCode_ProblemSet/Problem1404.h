//
// Created by HP on 5/29/2024.
//

#ifndef PROBLEM1404_H
#define PROBLEM1404_H
#include <string>


class Solution {
public:
    int numSteps(std::string s) {
        int steps = 0;
        bool carry = false;
        for(int i = s.size() - 1; i > 0; i--) {
            if((s[i] == '1' && !carry) || (s[i] == '0' && carry)) {
                steps += 2;
                carry = true;
            } else {
                steps++;
            }
        }
        return steps + carry;
    }
};



#endif //PROBLEM1404_H
