//
// Created by HP on 4/12/2024.
//

#ifndef PROBLEM219_H
#define PROBLEM219_H
#include <unordered_map>
#include <vector>


class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, std::vector<int>> map;
        for(int i = 0; i < nums.size(); i++) {
            auto it = map.find(nums[i]);
            if(it == map.end()) {
                std::vector<int> temp = {i};
                map[nums[i]] = temp;
            } else {
                for(int j = 0; j < it->second.size(); j++)
                    if(abs(i - it->second[j]) <= k)
                        return true;
                it->second.push_back(i);
            }
        }
        return false;
    }
};



#endif //PROBLEM219_H
