#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::vector<std::vector<bool>> rows(9, std::vector<bool> (9, false));
        std::vector<std::vector<bool>> cols(9, std::vector<bool> (9, false));
        std::vector<std::vector<bool>> cells(9, std::vector<bool> (9, false));
        for(int i = 0; i < 9; i++) 
            for(int j = 0; j < 9; j++)
                if(board[i][j] == '.')
                    continue;
                else if (rows[i][board[i][j] - '1'] ||
                    cols[j][board[i][j] - '1'] ||
                    cells[floor((double)i / 3) * 3 + floor((double)j / 3)][board[i][j] - '1'])
                    return false;
                else 
                    rows[i][board[i][j] - '1'] = cols[j][board[i][j] - '1'] = 
                    cells[floor((double)i / 3) * 3 + floor((double)j / 3)][board[i][j] - '1'] = true;
        return true;
    }
};