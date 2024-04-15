//
// Created by HP on 4/16/2024.
//

#ifndef PROBLEM867_H
#define PROBLEM867_H
#include <vector>


class Solution {
public:
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) {
        std::vector<std::vector<int>> answer(matrix[0].size(), std::vector<int> (matrix.size(), 0));
        for(int i = 0; i < matrix[0].size(); i++)
            for(int j = 0; j < matrix.size(); j++)
                answer[i][j] = matrix[j][i];
        return answer;
    }
};


#endif //PROBLEM867_H
