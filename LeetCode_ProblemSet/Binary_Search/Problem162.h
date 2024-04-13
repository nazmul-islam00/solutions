//
// Created by HP on 4/12/2024.
//

#ifndef PROBLEM162_H
#define PROBLEM162_H
#include <vector>


class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        if(nums.size() == 2) {
            return nums[0] > nums[1] ? 0 : 1;
        }
        int lower = 0;
        int upper = nums.size() - 1;
        int mid = (lower + upper) / 2;
        while(true) {
            if(mid - 1 != -1 && nums[mid - 1] > nums[mid]) {
                upper = mid - 1;
                mid = (lower + upper) / 2;
            } else if(mid + 1 != nums.size() && nums[mid + 1] > nums[mid]) {
                lower = mid + 1;
                mid = (lower + upper) / 2;
            } else
                return mid;
        }
        return -1;
    }
};



#endif //PROBLEM162_H
