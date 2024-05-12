//
// Created by HP on 5/12/2024.
//

#ifndef PROBLEM2373_H
#define PROBLEM2373_H
#include <vector>


class Solution {
public:
    int getMax(std::vector<int> num) {
        int maxNum = num[0];
        for(int i = 1; i < num.size(); i++) {
            maxNum = std::max(num[i], maxNum);
        }
        return maxNum;
    }
    std::vector<std::vector<int>> largestLocal(std::vector<std::vector<int>>& grid) {
        std::vector<std::vector<int>> answer;
        for(int i = 1; i < grid.size() - 1; i++) {
            std::vector<int> row;
            for(int j = 1; j < grid.size() - 1; j++) {
                row.push_back(getMax({grid[i - 1][j - 1], grid[i - 1][j], grid[i - 1][j + 1],
                                       grid[i][j - 1], grid[i][j], grid[i][j + 1],
                                       grid[i + 1][j - 1], grid[i + 1][j], grid[i + 1][j + 1]}));
            }
            answer.push_back(row);
        }
        return answer;
    }
};



#endif //PROBLEM2373_H
