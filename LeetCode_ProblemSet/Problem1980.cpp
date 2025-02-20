#include <string>
#include <vector>


class Solution {
public:
    std::string findDifferentBinaryString(std::vector<std::string>& nums) {
        std::string answer(nums.size(), '0');
        // using diagonalization
        for (int i = 0; i < nums.size(); i++) {
            answer[i] = (nums[i][i] == '1') ? '0' : '1';
        }
        return answer;
    }
};