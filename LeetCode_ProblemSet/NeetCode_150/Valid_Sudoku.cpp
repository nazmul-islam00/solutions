#include <unordered_set>
#include <vector>

class Solution {
   public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::vector<std::unordered_set<int>> rowSets(9), colSets(9), gridSets(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (board[i][j] < '0' || board[i][j] > '9') return false;

                int num = board[i][j] - '0';
                int gridIdx = getGrid(i, j);

                if (rowSets[i].find(num) != rowSets[i].end()) return false;
                if (colSets[j].find(num) != colSets[j].end()) return false;
                if (gridSets[gridIdx].find(num) != gridSets[gridIdx].end()) return false;

                rowSets[i].insert(num);
                colSets[j].insert(num);
                gridSets[gridIdx].insert(num);
            }
        }

        return true;
    }

   private:
    int getGrid(int i, int j) {
        return std::floor(i / 3) * 3 + std::floor(j / 3);
    }
};