#include <vector>
#include <string>

class Solution {
private:
    std::vector<std::vector<char>> board;
    std::vector<std::vector<bool>> visited;
    std::string word;
    int m, n;

    std::vector<int> dx = {-1, 0, 0, 1};
    std::vector<int> dy = {0, -1, 1, 0};

private:
    bool exist_helper(int row, int col, int pos) {
        if (pos == word.length()) return true;
        if (row < 0 || row >=this->m) return false;
        if (col < 0 || col >= this->n) return false;
        if (visited[row][col] || this->board[row][col] != this->word[pos]) return false;

        visited[row][col] = true;
        for (int i = 0; i < this->dx.size(); i++) {
            int new_row = row + this->dx[i], new_col = col + this->dy[i];
            if (this->exist_helper(new_row, new_col, pos + 1)) return true;
        }
        visited[row][col] = false;
        return false;
    }

public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        this->board = board, this->word = word;
        this->m = board.size(), this->n = board[0].size(); 
        this->visited = std::vector<std::vector<bool>>(m, std::vector<bool>(n));

        for (int row = 0; row < this->m; row++) {
            for (int col = 0; col < this->n; col++) {
                if (this->exist_helper(row, col, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};