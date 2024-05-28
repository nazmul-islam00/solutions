//
// Created by HP on 5/28/2024.
//

#ifndef PROBLEM1208_H
#define PROBLEM1208_H
#include <string>
#include <vector>


class Solution {
public:
    int equalSubstring(std::string s, std::string t, int maxCost) {
        std::vector<int> costs(s.size());
        for(int i = 0;  i < s.size(); i++) {
            costs[i] = std::abs(s[i] - t[i]);
        }
        int maxLength = 0, ind = 0, currCost = 0, currIndex = 0, currLength = 0;
        while(ind < s.size()) {
            if(costs[ind] + currCost <= maxCost) {
                currCost += costs[ind++];
                currLength++;
            } else {
                maxLength = std::max(maxLength, currLength);
                if(currIndex != ind) {
                    currCost -= costs[currIndex];
                }
                currIndex++;
                if(currLength) {
                    currLength--;
                }
            }
            ind = std::max(ind, currIndex);
        }
        maxLength = std::max(maxLength, currLength);
        return maxLength;
    }
};



#endif //PROBLEM1208_H
