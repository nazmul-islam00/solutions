#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

class Solution {
   private:
    std::vector<int> changeX = {-1, 1, 0, 0};
    std::vector<int> changeY = {0, 0, -1, 1};

   public:
    std::vector<int> maxPoints(std::vector<std::vector<int>>& grid, std::vector<int>& queries) {
        std::vector<std::pair<int, int>> sortedQueries;
        std::vector<int> answer(queries.size());
        sortedQueries.reserve(queries.size());

        for (int idx = 0; idx < queries.size(); idx++) {
            sortedQueries.emplace_back(queries[idx], idx);
        }
        std::sort(sortedQueries.begin(), sortedQueries.end());

        using T = std::tuple<int, int, int>;
        std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));

        pq.emplace(grid[0][0], 0, 0);
        visited[0][0] = true;

        int cnt = 0;
        for (const auto& p : sortedQueries) {
            int query = p.first, idx = p.second;

            while (!pq.empty() && std::get<0>(pq.top()) < query) {
                auto [_, x, y] = pq.top();
                pq.pop();
                cnt++;

                for (int i = 0; i < changeX.size(); i++) {
                    int row = x + changeX[i], col = y + changeY[i];

                    if (isInGrid(grid.size(), grid[0].size(), row, col) && !visited[row][col]) {
                        visited[row][col] = true;
                        pq.emplace(grid[row][col], row, col);
                    }
                }
            }
            answer[idx] = cnt;
        }

        return answer;
    }

   private:
    bool isInGrid(int m, int n, int row, int col) {
        return 0 <= row && row < m && 0 <= col && col < n;
    }
};