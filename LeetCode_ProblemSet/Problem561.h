//
// Created by HP on 4/17/2024.
//

#ifndef PROBLEM561_H
#define PROBLEM561_H
#include <vector>
#include <algorithm>


class Solution {
public:
    int arrayPairSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i< nums.size(); i += 2)
            sum += nums[i];
        return sum;
    }
};


#endif //PROBLEM561_H
