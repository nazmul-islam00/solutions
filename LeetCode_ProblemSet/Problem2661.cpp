#include <vector>
#include <unordered_map>


class Solution {
public:
    int firstCompleteIndex(std::vector<int>& arr, std::vector<std::vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        std::vector<std::pair<int, int>> positions = std::vector<std::pair<int, int>>(m * n);
        std::unordered_map<int, int> rowCnt, colCnt;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                positions[mat[i][j] - 1] = {i, j};
            }
        }

        for (int i = 0; i < m * n; i++) {
            auto pos = positions[arr[i] - 1];
            int row = pos.first, col = pos.second;

            if (rowCnt.find(row) == rowCnt.end()) rowCnt[row] = 1;
            else rowCnt[row]++;

            if (colCnt.find(col) == colCnt.end()) colCnt[col] = 1;
            else colCnt[col]++;

            if (rowCnt[row] == n || colCnt[col] == m) return i;
        }
        
        return 0;
    } 
};  