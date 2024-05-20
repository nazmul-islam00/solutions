//
// Created by HP on 5/20/2024.
//

#ifndef PROBLEM1863_H
#define PROBLEM1863_H
#include <cmath>
#include <vector>


class Solution {
public:
    int subsetXORSum(std::vector<int>& nums) {
        int sum = 0;
        for(int i : nums) {
            sum |= i;
        }
        return sum * std::pow(2, nums.size() - 1);
    }
};



#endif //PROBLEM1863_H
