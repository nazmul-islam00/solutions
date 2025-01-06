#include <string>
#include <vector>


class Solution {
public:
    std::vector<int> minOperations(std::string boxes) {
        std::vector<int> answer = std::vector<int>(boxes.size(), 0);
        int ballsLeft = 0, ballsRight = 0, movesLeft = 0, movesRight = 0;
        
        for (int i = 0; i < boxes.size(); i++) {
            answer[i] += movesLeft;
            ballsLeft += (boxes[i] == '1') ? 1 : 0;
            movesLeft += ballsLeft;

            int j = boxes.size() - 1 - i;
            answer[j] += movesRight;
            ballsRight += (boxes[j] == '1') ? 1 : 0;
            movesRight += ballsRight;
        }

        return answer;
    }
};