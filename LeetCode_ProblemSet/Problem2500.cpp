#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int deleteGreatestValue(std::vector<std::vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int answer = 0;
        std::vector<std::priority_queue<int, std::vector<int>, std::greater<int>>> heaps(n, std::priority_queue<int, std::vector<int>, std::greater<int>>());

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                heaps[i].push(grid[i][j]);
            }
        }

        for (int i = 0; i < m; i++) {
            int inc = 0;
            for (int j = 0; j < n; j++) {
                inc = std::max(inc, heaps[j].top());
                heaps[j].pop();
            }
            answer += inc;
        }

        return answer;
    }
};