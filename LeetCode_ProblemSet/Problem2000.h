//
// Created by HP on 5/1/2024.
//

#ifndef PROBLEM2000_H
#define PROBLEM2000_H
#include <algorithm>
#include <string>


class Solution {
public:
    std::string reversePrefix(std::string word, char ch) {
        int ind = -1;
        for(int i = 0; i < word.length(); i++) {
            if(word[i] == ch) {
                ind = i;
                break;
            }
        }
        if(ind == -1) {
            return word;
        }
        std::reverse(word.begin(), word.begin() + ind + 1);
        return word;
    }
};



#endif //PROBLEM2000_H
