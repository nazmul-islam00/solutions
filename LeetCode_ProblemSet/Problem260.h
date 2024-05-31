//
// Created by HP on 5/31/2024.
//

#ifndef PROBLEM260_H
#define PROBLEM260_H
#include <vector>


class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        if(nums.size() == 2) {
            return nums;
        }
        int xorVal = 0;
        // xorVal has the xor of the single nums at the end
        for(int num : nums) {
            xorVal ^= num;
        }
        int pos = 0;
        // pos has the position of the first differing bits of the single nums
        while(((1 << pos) & xorVal) == 0) {
            pos++;
        }
        int num1 = 0;
        // num1 is xored with the nums having 1 at pos
        // at the end it has one of the single nums
        for(int num : nums) {
            if(((1 << pos) & num) != 0) {
                num1 ^= num;
            }
        }
        return {num1, xorVal ^ num1};
    }
};



#endif //PROBLEM260_H
