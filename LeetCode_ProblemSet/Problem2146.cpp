#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

struct Distance {
    int distance;
    int row;
    int col;

    Distance(int dist, int r, int c) 
        : distance(dist), row(r), col(c) 
    {}
};

struct Item {
    int distance;
    int price;
    int row;
    int col;

    Item(int dist, int pr, int r, int c) 
        : distance(dist), price(pr), row(r), col(c) 
    {}
};

class Compare {
public:
    bool operator()(Item item1, Item item2) {
        if (item1.distance == item2.distance && item1.price == item2.price && item1.row == item2.row) {
            return item1.col < item2.col;
        }
        if (item1.distance == item2.distance && item1.price == item2.price) {
            return item1.row < item2.row;
        }
        if (item1.distance == item2.distance) {
            return item1.price < item2.price;
        }
        return item1.distance < item2.distance;
    }
};

class Solution {
public:
    std::vector<std::vector<int>> highestRankedKItems(std::vector<std::vector<int>>& grid, std::vector<int>& pricing, std::vector<int>& start, int k) {
        int row = start[0], col = start[1];
        int low = pricing[0], high = pricing[1];
        int n = grid.size(), m = grid[0].size();
        int changeX[] = {-1, 0, 0, 1};
        int changeY[] = {0, -1, 1, 0};

        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
        std::vector<std::vector<int>> answer;
        answer.reserve(k);
        std::priority_queue<Item, std::vector<Item>, Compare> heap;
        std::queue<Distance> bfsQueue;

        visited[row][col] = true;
        bfsQueue.push(Distance(0, row, col));
        if (grid[row][col] >= low && grid[row][col] <= high) {
            heap.push(Item(0, grid[row][col], row, col));
        }

        while (!bfsQueue.empty()) {
            Distance cur = bfsQueue.front();
            bfsQueue.pop();

            for (int i = 0; i < 4; i++) {
                int x = cur.row + changeX[i], y = cur.col + changeY[i];
                if (x < 0 || 
                    x >= n || 
                    y < 0 || 
                    y >= m || 
                    grid[x][y] == 0 ||
                    visited[x][y]) {
                    continue;
                }

                bfsQueue.push(Distance(cur.distance + 1, x, y));
                visited[x][y] = true;
                if (grid[x][y] == 1) {
                    continue;
                } 

                if (low <= grid[x][y] && high >= grid[x][y]) {
                    heap.push(Item(cur.distance + 1, grid[x][y], x, y));
                    if (heap.size() > k) {
                        heap.pop();
                    }
                }
            }
        }

        k = std::min(k, (int)heap.size());
        for (int i = 0; i < k; i++) {
            Item cur = heap.top();
            heap.pop();
            answer.emplace_back(std::vector<int>{cur.row, cur.col});
        }
        std::reverse(answer.begin(), answer.end());
        
        return answer;
    }
};