#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        std::vector<std::vector<int>> copy = matrix;
        for(int i = 0; i < matrix.size(); i++) 
            for(int j = 0; j < matrix[0].size(); j++) 
                if(!matrix[i][j]) {
                    for(int k= 0; k < matrix.size(); k++) 
                        copy[k][j] = 0;
                    for(int l = 0; l < matrix[0].size(); l++) 
                        copy[i][l] = 0;
                }
        matrix = copy;
    }
};