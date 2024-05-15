//
// Created by HP on 5/15/2024.
//

#ifndef PROBLEM2812_H
#define PROBLEM2812_H
#include <cmath>
#include <vector>
#include <queue>

class Solution {
    int getDist(std::vector<std::pair<int, int>> thieves, std::vector<std::vector<int>>& dist, int rows, int cols) {
        std::queue<std::pair<int, int>> bfsQueue;
        std::vector<int> directions = {0, 1, 0, -1, 0};
        std::vector<std::vector<bool>> visited(rows, std::vector<bool> (cols, false));
        for(auto p : thieves) {
            visited[p.first][p.second] = true;
            bfsQueue.push(p);
        }
        int maxDist = 0;
        while(!bfsQueue.empty()) {
            auto pos = bfsQueue.front();
            bfsQueue.pop();
            for(int direction = 0; direction < 4; direction++) {
                int row = pos.first + directions[direction], col = pos.second + directions[direction + 1];
                if(row < 0 || col < 0 || row == rows || col == cols || visited[row][col]) {
                    continue;
                }
                visited[row][col] = true;
                dist[row][col] = dist[pos.first][pos.second] + 1;
                bfsQueue.push({row, col});
                maxDist = std::max(maxDist, dist[row][col]);
            }
        }
        return maxDist;
    }
    bool pathExists(std::vector<std::vector<int>>& dist, int limit, int rows, int cols) {
        if(dist[0][0] < limit) {
            return false;
        }
        std::vector<int> directions = {0, 1, 0, -1, 0};
        std::vector<std::vector<bool>> visited(rows, std::vector<bool> (cols, false));
        std::queue<std::pair<int, int>> bfsQueue;
        bfsQueue.push({0, 0 });
        visited[0][0] = true;
        while(!bfsQueue.empty()) {
            auto pos = bfsQueue.front();
            bfsQueue.pop();
            // end reached
            if(pos.first == rows - 1 && pos.second == cols - 1) {
                return true;
            }
            for(int direction = 0; direction < 4; direction++) {
                int row = pos.first + directions[direction], col = pos.second + directions[direction + 1];
                if(row < 0 || col < 0 || row == rows || col == cols || dist[row][col] == 0 || visited[row][col] || dist[row][col] < limit) {
                    continue;
                }
                visited[row][col] = true;
                bfsQueue.push({row, col});
            }
        }
        return false;
    }
public:
    int maximumSafenessFactor(std::vector<std::vector<int>>& grid) {
        // thieves positions
        std::vector<std::pair<int, int>> thieves;
        int rows = grid.size(), cols = grid[0].size();
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                if(grid[row][col] == 1) {
                    thieves.push_back({row, col});
                }
            }
        }
        // min distance from thieves
        std::vector<std::vector<int>> dist(rows, std::vector<int> (cols, 0));
        int maxDist = getDist(thieves, dist, rows, cols);
        int low = 0, high = maxDist, answer = 0;
        while(low <= high) {
            int mid = ceil((double)(low + high) / 2);
            if(pathExists(dist, mid, rows, cols)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return answer;
    }
};



#endif //PROBLEM2812_H
