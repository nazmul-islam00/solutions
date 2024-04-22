#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <limits>
#define NOT_VISITED std::numeric_limits<uint16_t>::max()

std::ofstream out("output.txt", std::ios_base::ate);

class Solution {
private:
    std::vector<int> row = {-1, 0, 0, 1};
    std::vector<int> col = {0, -1, 1, 0};
    void bfs(std::vector<std::vector<uint16_t>>& distanceMatrix, uint16_t sourceX, uint16_t sourceY) {
        distanceMatrix[sourceX][sourceY] = 0;
        std::queue<std::pair<std::pair<uint16_t, uint16_t>, uint16_t>> bfsQueue;
        std::vector<std::vector<bool>> visited(distanceMatrix.size(), std::vector<bool> (distanceMatrix[0].size(), false));
        visited[sourceX][sourceY] = true;
        bfsQueue.push({{sourceX, sourceY}, 0});
        while(!bfsQueue.empty()) {
            auto p = bfsQueue.front();
            bfsQueue.pop();
            uint16_t currX = p.first.first, currY = p.first.second, currDist = p.second;
            for(uint16_t i = 0; i < this->row.size(); i++) {
                int targetX = currX + this->row[i], targetY = currY + this->col[i];
                if (targetX >= 0 && targetX < distanceMatrix.size() &&
                    targetY >= 0 && targetY < distanceMatrix[0].size() &&
                    !visited[targetX][targetY]) {
                    distanceMatrix[targetX][targetY] = std::min(currDist + 1, (int)distanceMatrix[targetX][targetY]);
                    visited[targetX][targetY] = true;
                    bfsQueue.push({{targetX, targetY}, distanceMatrix[targetX][targetY]});
                }
            }
        }
    }
    void printResult(std::vector<std::vector<uint16_t>>& distanceMatrix) {
        uint16_t maxDistance = 0, maxX = 0, maxY = 0;
        for(int i = 0; i < distanceMatrix.size(); i++) {
            for(uint16_t j = 0; j < distanceMatrix[0].size(); j++) {
                if(distanceMatrix[i][j] > maxDistance) {
                    maxDistance = distanceMatrix[i][j];
                    maxX = i, maxY = j;
                }
            }
        }
        out << maxX + 1 << " " << maxY + 1; 
        out.close();
    }
public:
    void run() {
        uint16_t n, m, k;
        std::cin >> n >> m >> k;
        std::vector<std::pair<int, uint16_t>> start;
        for(uint16_t i = 0; i < k; i++) {
            uint16_t x, y;
            std::cin >> x >> y;
            start.push_back({x - 1, y - 1});
        }
        std::vector<std::vector<uint16_t>> distanceMatrix(n, std::vector<uint16_t>(m, NOT_VISITED));
        for(int i = 0; i < k; i++) {
            this->bfs(distanceMatrix, start[i].first, start[i].second);
        }
        this->printResult(distanceMatrix);
    }
};

