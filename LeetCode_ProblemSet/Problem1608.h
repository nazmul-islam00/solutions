//
// Created by HP on 5/27/2024.
//

#ifndef PROBLEM1608_H
#define PROBLEM1608_H
#include <algorithm>
#include <vector>


class Solution {
public:
    int specialArray(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](auto num1, auto num2) {
            return num1 > num2;
        });
        for(int i = 1; i <= nums.size(); i++) {
            if(nums[i - 1] >= i) {
                if(i < nums.size() && nums[i] >= i) {
                } else {
                    return i;
                }
            }
        }
        return -1;
    }
};



#endif //PROBLEM1608_H
