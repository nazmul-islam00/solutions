//
// Created by HP on 4/12/2024.
//

#ifndef PROBLEM739_H
#define PROBLEM739_H
#include <queue>
#include <vector>


class Solution {
public:
    static std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> answer(temperatures.size(), 0);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        for(int i = 0; i < temperatures.size(); i++) {
            while(!pq.empty() && pq.top().first < temperatures[i]) {
                answer[pq.top().second] = i - pq.top().second;
                pq.pop();
            }
            pq.push({temperatures[i], i});
        }
        return answer;
    }
};



#endif //PROBLEM739_H
