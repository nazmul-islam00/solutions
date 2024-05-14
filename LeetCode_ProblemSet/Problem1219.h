//
// Created by HP on 5/14/2024.
//

#ifndef PROBLEM1219_H
#define PROBLEM1219_H
#include <vector>


class Solution {
    int getMaxGold(std::vector<std::vector<int>>& grid, int row, int col) {
        // out of range
        // or no gold
        if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size() || !grid[row][col]) {
            return 0;
        }
        int maxGold = 0;
        int ogVal = grid[row][col];
        // mark visited
        grid[row][col] = 0;
        maxGold = std::max(maxGold, getMaxGold(grid, row - 1, col)); // up
        maxGold = std::max(maxGold, getMaxGold(grid, row + 1, col)); // down
        maxGold = std::max(maxGold, getMaxGold(grid, row, col - 1)); // left
        maxGold = std::max(maxGold, getMaxGold(grid, row, col + 1)); // right
        grid[row][col] = ogVal;
        // current gold + recursive answer
        return maxGold + ogVal;
    }
public:
    int getMaximumGold(std::vector<std::vector<int>>& grid) {
        int maxGold = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j =0; j < grid[0].size(); j++) {
                maxGold = std::max(maxGold, getMaxGold(grid, i, j));
            }
        }
        return maxGold;
    }
};



#endif //PROBLEM1219_H
