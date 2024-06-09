//
// Created by HP on 6/9/2024.
//

#ifndef PROBLEM974_H
#define PROBLEM974_H
#include <unordered_map>
#include <vector>


class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        std::vector<int> uniqueSums;
        std::unordered_map<int, int> sums;
        int ans = 0;
        int sum = 0;

        for(int num : nums) {
            sum += num;
            auto it = sums.find(((sum % k) + k) % k);

            if(it == sums.end()) {
                uniqueSums.push_back(((sum % k) + k) % k);
                sums[((sum % k) + k) % k] = 1;
            } else {
                it->second = it->second + 1;
            }
        }

        for(int uniqueSum : uniqueSums) {
            int cnt = sums.find(uniqueSum)->second;
            ans += cnt * (cnt - 1) / 2;
        }

        auto it = sums.find(0);
        if(it != sums.end()) {
            ans += it->second;
        }

        return ans;
    }
};




#endif //PROBLEM974_H

