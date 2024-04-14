//
// Created by HP on 4/15/2024.
//

#ifndef PROBLEM14_H
#define PROBLEM14_H
#include <string>
#include <vector>


class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if(strs.size() == 1) return strs[0];
        std::string answer = "";
        int curr = 0;
        for(int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][curr];
            for(int j = 1; j < strs.size(); j++) {
                if(curr >= strs[j].length() || strs[j][curr] != c)
                    return answer;
            }
            answer += c;
            curr++;
        }
        return answer;
    }
};


#endif //PROBLEM14_H
