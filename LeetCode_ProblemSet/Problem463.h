//
// Created by HP on 4/16/2024.
//

#ifndef PROBLEM463_H
#define PROBLEM463_H
#include <vector>


class Solution {
    int getConnectedTiles(std::vector<std::vector<int>>& grid, int row, int col) {
        int connectedTiles = 0;
        if(row == 0 || !grid[row - 1][col]) connectedTiles++;
        if(row == grid.size() - 1 || !grid[row + 1][col]) connectedTiles++;
        if(col == 0 || !grid[row][col - 1]) connectedTiles++;
        if(col == grid[0].size() - 1 || !grid[row][col + 1]) connectedTiles++;
        return connectedTiles;
    }
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        int answer = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j])
                    answer += getConnectedTiles(grid, i, j);
        return answer;
    }
};


#endif //PROBLEM463_H
