#include <vector>
#include <queue>


class Solution {
private:
    struct Node {
        int x, y, distance;

        Node(int x, int y, int distance) : x(x), y(y), distance(distance) {}
    };

    std::vector<int> changeX = {0, 0, 1, -1};
    std::vector<int> changeY = {1, -1, 0, 0};

public:
    int minCost(std::vector<std::vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<int>> distance = std::vector<std::vector<int>>(m, std::vector<int>(n, m * n));
        std::queue<Node> bfsQueue;
        bfsQueue.push(Node(0, 0, 0));
        distance[0][0] = 0;

        while (!bfsQueue.empty()) {
            Node curr = bfsQueue.front();
            bfsQueue.pop();

            int direction = grid[curr.x][curr.y];
            if (isInsideGrid(curr.x + changeX[direction - 1], curr.y + changeY[direction - 1], m, n) && distance[curr.x + changeX[direction - 1]][curr.y + changeY[direction - 1]] > curr.distance) {
                bfsQueue.push(Node(curr.x + changeX[direction - 1], curr.y + changeY[direction - 1], curr.distance));
                distance[curr.x + changeX[direction - 1]][curr.y + changeY[direction - 1]] = curr.distance;
            }

            for (int i = 0; i < changeX.size(); i++) {
                if (i + 1 == direction) continue;
                if (!isInsideGrid(curr.x + changeX[i], curr.y + changeY[i], m, n)) continue;
                if (distance[curr.x + changeX[i]][curr.y + changeY[i]] <= curr.distance + 1) continue;

                bfsQueue.push(Node(curr.x + changeX[i], curr.y + changeY[i], curr.distance + 1));
                distance[curr.x + changeX[i]][curr.y + changeY[i]] = curr.distance + 1;
            }
        }

        return distance[m - 1][n - 1];
    }

private:
    bool isInsideGrid(int i, int j, int m, int n) {
        return 0 <= i && i < m && 0 <= j && j < n;
    }
};