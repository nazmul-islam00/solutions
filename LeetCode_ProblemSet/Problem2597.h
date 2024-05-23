//
// Created by HP on 5/23/2024.
//

#ifndef PROBLEM2597_H
#define PROBLEM2597_H
#include <cmath>
#include <unordered_map>
#include <vector>


class Solution {
public:
    int beautifulSubsets(std::vector<int>& nums, int k) {
        std::vector<std::vector<short>> ans(std::pow(2, nums.size()), std::vector<short> ());
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
        ans.pop_back();
        int cnt = 0;
        for(int i = 0; i < ans.size(); i++) {
            std::unordered_map<short, short> map;
            bool isBeautiful = true;
            for(int j = 0; j < ans[i].size(); j++) {
                if(map.find(ans[i][j] - k) == map.end() && map.find(k + ans[i][j]) == map.end()) {
                    map[ans[i][j]] = ans[i][j];
                } else {
                    isBeautiful = false;
                     break;
                }
            }
            if(isBeautiful) {
                cnt++;
            }
        }
        return cnt;
    }
};





#endif //PROBLEM2597_H
