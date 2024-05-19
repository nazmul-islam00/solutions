//
// Created by HP on 5/19/2024.
//

#ifndef PROBLEM3068_H
#define PROBLEM3068_H
#include <iostream>
#include <vector>


class Solution {
public:
    long long maximumValueSum(std::vector<int>& nums, int k, std::vector<std::vector<int>>& edges) {
        /*
         * as the graph is a tree, any two nodes have a path between them
         * taking any pair of vertices the values can be changed
         * if any other vertices are included in the path
         * then those vertices get changed twice returning to tthe original value
         * store increasing, decreasing and unchanged values
         * swap the lowest of increases with the last of the list
         * now for every two vertices in the list chnnge them
         * if a lone vertex is left search for equal vertices
         * if equal vertices exist choose any of them and change both
         * else look for decreasing vertices
         * find the lowest decrease
         * now add the last increase which is the lowest increase with the lowest decrease
         * if the sum is positive then change both values
         */
        std::vector<int>  equalIndices;
        std::vector<std::pair<int, int>> increasingIndices, decreasingIndices;
        for(int i = 0; i < nums.size(); i++) {
            if((nums[i] ^ k) > nums[i]) {
               increasingIndices.push_back({i, (nums[i] ^ k) - nums[i]});
            } else if ((nums[i] ^ k) == nums[i]) {
                equalIndices.push_back(i);
            } else {
                decreasingIndices.push_back({i, (nums[i] ^ k) - nums[i]});
            }
        }
        int minGain = INT16_MAX;
        int minGainIndex = -1;
        for(int i = 0; i < increasingIndices.size(); i++) {
            if(minGain > increasingIndices[i].second) {
                minGain = increasingIndices[i].second;
                minGainIndex = i;
            }
        }
        if(minGainIndex != - 1) {
            auto p = increasingIndices[increasingIndices.size() - 1];
            increasingIndices[increasingIndices.size() - 1] = increasingIndices[minGainIndex];
            increasingIndices[minGainIndex] = p;
        }
        if(increasingIndices.size() > 1) {
            for(int i = 0; i < increasingIndices.size() - 1; i += 2) {
                nums[increasingIndices[i].first] ^= k;
                nums[increasingIndices[i + 1].first] ^= k;
            }
        }
        if(increasingIndices.size() % 2 && !equalIndices.empty()) {
            nums[increasingIndices[increasingIndices.size() - 1].first] ^= k;
        } else if(increasingIndices.size() % 2 && !decreasingIndices.empty()) {
            int gain = increasingIndices[increasingIndices.size() - 1].second;
            int minLoss = decreasingIndices[0].second;
            int minLossIndex = 0;
            for(int i = 1; i < decreasingIndices.size(); i++) {
                if(minLoss < decreasingIndices[i].second) {
                    minLoss = decreasingIndices[i].second;
                    minLossIndex = i;
                }
            }
            if(gain + minLoss > 0) {
                nums[increasingIndices[increasingIndices.size() - 1].first] ^= k;
                nums[decreasingIndices[minLossIndex].first] ^= k;
            }
        }
        long long res = 0;
        for(int i : nums) {
            res += i;
        }
        return res;
    }
};



#endif //PROBLEM3068_H
