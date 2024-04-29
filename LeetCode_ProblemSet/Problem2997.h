//
// Created by HP on 4/29/2024.
//

#ifndef PROBLEM2997_H
#define PROBLEM2997_H
#include <vector>


class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        int odd = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            odd ^= nums[i];
        }
        int res = odd ^ k;
        int changes = bitset<32>(res).count();
        return changes;
    }
};



#endif //PROBLEM2997_H
