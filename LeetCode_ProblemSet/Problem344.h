//
// Created by HP on 6/2/2024.
//

#ifndef PROBLEM344_H
#define PROBLEM344_H
#include <vector>


class Solution {
public:
    void reverseString(std::vector<char>& s) {
        char c;
        for(int i = 0; i < s.size() / 2; i++) {
            c = s[i];
            s[i] = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = c;
        }
    }
};



#endif //PROBLEM344_H
