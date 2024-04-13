//
// Created by HP on 4/13/2024.
//

#ifndef PROBLEM1768_H
#define PROBLEM1768_H
#include <string>


class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        std::string result = "";
        for(int i = 0; i < std::min(l1, l2); i++) {
            result += word1[i];
            result += word2[i];
        }
        if(l1 > l2)
            for(int i = l2; i < l1; i++)
                result += word1[i];
        else
            for(int i = l1; i < l2; i++)
                result += word2[i];
        return result;
    }
};



#endif //PROBLEM1768_H
