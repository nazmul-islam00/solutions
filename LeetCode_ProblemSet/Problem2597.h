//
// Created by HP on 5/23/2024.
//

#ifndef PROBLEM2597_H
#define PROBLEM2597_H
#include <cmath>
#include <unordered_map>
#include <vector>


class Solution {
private:
    // currIndex: index of the element being considered
    // mask: as the subset contains at most 20 bits, it's represented as a mask
    int countBeautifulSubsets(std::vector<int>& nums, int difference, int currIndex, int mask) {
        // reached the end of the vector
        // if any element was included to the subset it has value greater than 0, so count 1
        // else it is am empty subset, count 0
        if(currIndex == nums.size()) {
            return mask > 0 ? 1 : 0;
        }
        bool isBeautiful = true;
        // as the elements are considered sequentially, only checking till the currIndex is enough
        // the loop can terminate if any corresponding ugly element os found
        for(int j = 0; j < currIndex && isBeautiful; j++) {
            // push 1 to the corresponding index and check if it is already in the mask
            // if already in the mask check for difference
            isBeautiful = ((1 << j) & mask) == 0 || abs(nums[j] - nums[currIndex]) != difference;
        }
        // count subsets not including the currIndex element
        int skip = countBeautifulSubsets(nums, difference, currIndex + 1, mask);
        // if isBeautiful, count subsets from next Index including the currIndex
        // else 0
        int take = isBeautiful ? countBeautifulSubsets(nums, difference, currIndex + 1, mask + (1 << currIndex)) : 0;
        return skip + take;
    }
public:
    int beautifulSubsets(std::vector<int>& nums, int k) {
        return countBeautifulSubsets(nums, k, 0, 0);
    }
};





#endif //PROBLEM2597_H
