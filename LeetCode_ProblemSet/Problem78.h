//
// Created by HP on 5/21/2024.
//

#ifndef PROBLEM78_H
#define PROBLEM78_H
#include <cmath>
#include <vector>


class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans(std::pow(2, nums.size()), std::vector<int> ());
        for(int i = 0; i < nums.size(); i++) {
            int idx = 0;
            while(idx < ans.size()) {
                for(int j = 0; j < std::pow(2, nums.size() - 1 - i); j++) {
                    ans[idx++].push_back(nums[i]);
                }
                for(int j = 0; j < std::pow(2, nums.size() - 1 - i); j++) {
                    idx++;
                }
            }
        }
        return ans;
    }
};



#endif //PROBLEM78_H
