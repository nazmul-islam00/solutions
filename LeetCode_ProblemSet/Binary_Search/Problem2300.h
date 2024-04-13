//
// Created by HP on 4/12/2024.
//

#ifndef PROBLEM2300_H
#define PROBLEM2300_H
#include <algorithm>
#include <vector>


class Solution {
public:
    int getIndex(std::vector<int>& potions, long long success, int spell) {
        if((long long) spell * (long long) potions[potions.size() - 1] < success)
            return 0;
        int lower = 0;
        int upper = potions.size() - 1;
        int mid = (lower + upper) / 2;
        while(true) {
            if((long long) potions[mid] * (long long) spell >= success) {
                if(mid!= 0 && (long long) potions[mid-1] * (long long) spell >= success) {
                    upper = mid - 1;
                    mid = (lower + upper) / 2;
                } else {
                    return potions.size() - mid;
                }
            } else {
                lower = mid + 1;
                mid = (lower + upper) / 2;
            }
        }
        return 0;
    }

    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        std::vector<int> answer(spells.size(), 0);
        for(int i = 0; i < spells.size(); i++)
            answer[i] = getIndex(potions, success, spells[i]);
        return answer;
    }
};



#endif //PROBLEM2300_H
