//
// Created by HP on 5/13/2024.
//

#ifndef PROBLEM861_H
#define PROBLEM861_H
#include <vector>


class Solution {
public:
    int matrixScore(std::vector<std::vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < grid[0].size(); j++) {
                    grid[i][j] = grid[i][j] ? 0 : 1;
                }
            }
        }
        for(int i = 1; i < grid[0].size(); i++) {
            int cnt1 = 0, cnt0 = 0;
            for(int j = 0; j < grid.size(); j++) {
                grid[j][i] ? cnt1++ : cnt0++;
            }
            if(cnt0 > cnt1) {
                for(int j = 0; j < grid.size(); j++) {
                    grid[j][i] = grid[j][i] ? 0 : 1;
                }
            }
        }
        int answer = 0;
        for(int i = 0; i < grid.size(); i++) {
            int val = 0;
            for(int j = 0; j < grid[0].size(); j++) {
                val *= 2;
                val += grid[i][j];
            }
            answer += val;
        }
        return answer;
    }
};



#endif //PROBLEM861_H
