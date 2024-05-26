//
// Created by HP on 5/26/2024.
//

#ifndef PROBLEM552_H
#define PROBLEM552_H
#include <vector>


class Solution {
    int mod = 1000000007;
    std::vector<std::vector<std::vector<int>>> memo;
    int getRecords(int n, int absents, int consecutiveLates) {
        if(absents >= 2 || consecutiveLates >= 3) {
            return 0;
        }
        if(n == 0) {
            return 1;
        }
        if(memo[n][absents][consecutiveLates] != -1) {
            return memo[n][absents][consecutiveLates];
        }
        int count = getRecords(n - 1, absents, 0);
        count = (count + getRecords(n - 1, absents + 1, 0)) % mod;
        count = (count + getRecords(n - 1, absents, consecutiveLates + 1)) % mod;
        return memo[n][absents][consecutiveLates] = count;
    }
public:
    int checkRecord(int n) {
        memo = std::vector<std::vector<std::vector<int>>> (n + 1, std::vector<std::vector<int>> (2, std::vector<int> (3, -1)));
        return getRecords(n, 0, 0);
    }
};



#endif //PROBLEM552_H
