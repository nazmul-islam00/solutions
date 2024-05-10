//
// Created by HP on 5/10/2024.
//

#ifndef PROBLEM786_H
#define PROBLEM786_H
#include <algorithm>
#include <vector>


class Solution {
public:
    std::vector<int> kthSmallestPrimeFraction(std::vector<int>& arr, int k) {
        std::vector<std::pair<long double, std::pair<int, int>>> fractions;
        for(int i = 0; i < arr.size() - 1; i++) {
            for(int j = 0; j < arr.size(); j++) {
                fractions.push_back({(long double)arr[i] / (long double)arr[j], {arr[i], arr[j]}});
            }
        }
        std::sort(fractions.begin(), fractions.end(), [](auto f1, auto f2) {
            return f1.first < f2.first;
        });
        return {fractions[k - 1].second.first, fractions[k - 1].second.second};
    }
};



#endif //PROBLEM786_H
