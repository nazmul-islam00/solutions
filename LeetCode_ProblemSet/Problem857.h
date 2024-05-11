//
// Created by HP on 5/11/2024.
//

#ifndef PROBLEM857_H
#define PROBLEM857_H
#include <algorithm>
#include <cstdint>
#include <queue>
#include <vector>



class Solution {
public:
    double mincostToHireWorkers(std::vector<int>& quality, std::vector<int>& wage, int k) {
        std::vector<std::pair<double, std::pair<int, int>>> ratio;
        for(int i = 0; i < quality.size(); i++) {
            ratio.push_back({(double)wage[i] / (double)quality[i], {quality[i], wage[i]}});
        }
        sort(ratio.begin(), ratio.end(), [](auto r1, auto r2) {
            return r1.first < r2.first;
        });
        double answer;
        int totalQuality = 0;
        std::priority_queue<int> qualities;
        for(int i = 0; i < k; i++) {
            totalQuality += ratio[i].second.first;
            qualities.push(ratio[i].second.first);
        }
        answer = (double)totalQuality * ratio[k - 1].first;
        for(int i = k; i < quality.size(); i++) {
            totalQuality -= qualities.top();
            qualities.pop();
            totalQuality += ratio[i].second.first;
            qualities.push(ratio[i].second.first);
            answer = std::min(answer, (double)totalQuality * ratio[i].first);
        }
        return answer;
    }
};



#endif //PROBLEM857_H
