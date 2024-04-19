#include <vector>

class Solution {
    std::vector<int> rows = {-1, 0, 0, 1};
    std::vector<int> cols = {0, 1, -1, 0};
    void dfs(std::vector<std::vector<bool>>& visited, std::vector<std::vector<char>>& grid, int row, int col) {
        visited[row][col] = true;
        for(int i = 0; i < this->rows.size(); i++)
            if (row + rows[i] >= 0 && row + rows[i] < grid.size() &&
                col + cols[i] >= 0 && col + cols[i] < grid[0].size() &&
                grid[row + rows[i]][col + cols[i]] == '1' &&
                !visited[row + rows[i]][col + cols[i]])
                dfs(visited, grid, row + rows[i], col + cols[i]);
    }
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool> (grid[0].size(), false));
        int count = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == '1' && !visited[i][j]) {
                    dfs(visited, grid, i, j);
                    count++;
                }
        return count;
    }   
};