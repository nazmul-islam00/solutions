//
// Created by HP on 4/12/2024.
//

#ifndef PROBLEM503_H
#define PROBLEM503_H
#include <queue>
#include <vector>


class Solution {
public:
    static std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        std::vector<int> answer(nums.size(), -1);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        for(int i = 0; i < nums.size(); i++) {
            while(!pq.empty() && pq.top().first < nums[i]) {
                answer[pq.top().second] = nums[i];
                pq.pop();
            }
            pq.push({nums[i], i});
        }
        for(int i = 0; i < nums.size(); i++) {
            if(pq.size() == 1)
                break;
            while(pq.size() != 1 && pq.top().first < nums[i]) {
                answer[pq.top().second] = nums[i];
                pq.pop();
            }
        }
        return answer;
    }
};



#endif //PROBLEM503_H
