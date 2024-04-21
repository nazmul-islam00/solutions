#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define CHESS_BOARD_SIZE 8
#define NOT_VISITED 1e9
#define LEFT "L"
#define RIGHT "R"
#define UP "U"
#define DOWN "D"
#define LEFT_UP "LU"
#define LEFT_DOWN "LD"
#define RIGHT_UP "RU"
#define RIGHT_DOWN "RD"


class Solution {
private:
    std::vector<int> row = {-1, -1, -1, 0, 0, 1, 1, 1};
    std::vector<int> col = {-1, 0, 1, -1, 1, -1, 0, 1};
    std::vector<std::string> direction = {RIGHT_DOWN, DOWN, LEFT_DOWN, RIGHT, LEFT, RIGHT_UP, UP, LEFT_UP};
    void bfs(std::vector<std::vector<int>>& distanceMatrix, std::vector<std::vector<std::pair<int, int>>>& parentMatrix, int sourceX, int sourceY) {
        distanceMatrix[sourceX][sourceY] = 0;
        parentMatrix[sourceX][sourceY] = {sourceX, sourceY};
        std::queue<std::pair<std::pair<int, int>, int>> bfsQueue;
        bfsQueue.push({{sourceX, sourceY}, 0});
        while(!bfsQueue.empty()) {
            auto p = bfsQueue.front();
            bfsQueue.pop();
            int currX = p.first.first, currY = p.first.second, currDist = p.second;
            for(int i = 0; i < this->row.size(); i++) {
                int targetX = currX + this->row[i], targetY = currY + this->col[i];
                if (targetX >= 0 && targetX < distanceMatrix.size() &&
                    targetY >= 0 && targetY < distanceMatrix[0].size() &&
                    distanceMatrix[targetX][targetY] == NOT_VISITED) {
                    distanceMatrix[targetX][targetY] = currDist + 1;
                    parentMatrix[targetX][targetY] = {currX, currY};
                    bfsQueue.push({{targetX, targetY}, currDist + 1});
                }
            }
        }
    }
    std::vector<std::string> getPath(std::vector<std::vector<std::pair<int, int>>>& parentMatrix, int sourceX, int sourceY, int destX, int destY) {
        std::vector<std::string> path;
        int currX = destX, currY = destY;
        while(currX != sourceX || currY != sourceY) {
            for(int i = 0; i < this->row.size(); i++) {
                int newX = currX + this->row[i], newY = currY + this->col[i];
                int parentX = parentMatrix[currX][currY].first, parentY = parentMatrix[currX][currY].second;
                if(newX == parentX && newY == parentY) {
                    path.push_back(this->direction[i]);
                    currX = newX, currY = newY;
                    break;
                }
            }
        }
        std::reverse(path.begin(), path.end());
        return path;
    }
    void printResult(std::vector<std::string> path) {
        std::cout << path.size() << std::endl;
        for(std::string str : path) {
            std::cout << str << std::endl;
        }
    }
public:
    void run() {
        std::string source, dest;
        std::cin >> source >> dest;
        int sourceX = '8' - source[1], sourceY = source[0] - 'a';
        int destX = '8' - dest[1], destY = dest[0]- 'a';
        std::vector<std::vector<int>> distanceMatrix(CHESS_BOARD_SIZE, std::vector<int> (CHESS_BOARD_SIZE, NOT_VISITED));
        std::vector<std::vector<std::pair<int, int>>> parentMatrix(CHESS_BOARD_SIZE, std::vector<std::pair<int, int>> (CHESS_BOARD_SIZE, {-1, -1}));
        this->bfs(distanceMatrix, parentMatrix, sourceX, sourceY);
        this->printResult(this->getPath(parentMatrix, sourceX, sourceY, destX, destY));
    }
};
