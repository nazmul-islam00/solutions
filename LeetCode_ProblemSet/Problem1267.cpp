#include <vector>


class Solution {
public:
    int countServers(std::vector<std::vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int communicableServers = 0;
        std::vector<int> colCount = std::vector<int>(n, 0), lastColInRow = std::vector<int>(m, -1);

        for (int i = 0; i < m; i++) {
            int serversInRow = 0;

            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    serversInRow++;
                    lastColInRow[i] = j;
                    colCount[j]++;
                }
            }

            if (serversInRow > 1) {
                communicableServers += serversInRow;
                lastColInRow[i] = -1;
            }
        }

        for (int i = 0; i < m; i++) {
            if (lastColInRow[i] != -1 && colCount[lastColInRow[i]] > 1) {
                communicableServers += 1;
            }
        }

        return communicableServers;
    }
};