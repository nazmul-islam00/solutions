//
// Created by HP on 6/8/2024.
//

#ifndef PROBLEM523_H
#define PROBLEM523_H
#include <unordered_map>
#include <vector>


class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        // sum % k, 2 indices:
        // first one is the latest index,
        // second one is the one before the first one
        // these are indices with the same mod value
        std::unordered_map<int, std::pair<int, int>> subarraySum;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            // subarray from start
            if(sum % k == 0 && i >= 1) {
                return true;
            }

            auto pos = subarraySum.find(sum % k);

            if(pos == subarraySum.end()) {
                subarraySum[sum % k] = {i, -1};
            } else {
                // last occurence forms a subarray with size at least 2
                if(i - pos->second.first >= 2) {
                    return true;
                }

                // previous occurence forms a subarray with size at least 2
                if(pos->second.second != -1 and i - pos->second.second >= 2) {
                    return true;
                }

                pos->second = {i, pos->second.first};
            }
        }
        return false;
    }
};



#endif //PROBLEM523_H
