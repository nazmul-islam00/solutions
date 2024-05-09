//
// Created by HP on 5/9/2024.
//

#ifndef PROBLEM3075_H
#define PROBLEM3075_H
#include <algorithm>
#include <vector>


class Solution {
public:
    long long maximumHappinessSum(std::vector<int>& happiness, int k) {
        long long ans = 0;
        sort(happiness.begin(), happiness.end(), [](auto h1, auto h2) {
            return h1 > h2;
        });
        for(int i = 0; i < k; i++) {
            ans += (happiness[i] - i > 0) ? (happiness[i] - i) : 0;
        }
        return ans;
    }
};



#endif //PROBLEM3075_H
