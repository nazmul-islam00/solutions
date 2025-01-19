#include <vector>
#include <algorithm>


class Solution {
public:
    int trap(std::vector<int>& height) {
        if (height.size() == 1 || height.size() == 2) return 0;

        std::vector<int> heightLeft = std::vector<int>(height.size(), 0), heightRight = std::vector<int>(height.size(), 0);

        for (int i = 1; i < height.size(); i++) {
            heightLeft[i] = std::max(heightLeft[i - 1], height[i - 1]);
        }
        for (int i = height.size() - 2; i >= 0; i--) {
            heightRight[i] = std::max(heightRight[i + 1], height[i + 1]);
        }

        int answer = 0;
        for (int i = 0; i < height.size(); i++) {
            answer += std::max(std::min(heightLeft[i], heightRight[i]) - height[i], 0);
        }
        return answer;
    }
};