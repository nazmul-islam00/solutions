#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int n = height.size();
        int low = 0;
        int high = n - 1;
        int maxWater = 0;
        while(low < high) {
            maxWater = std::max(maxWater, std::min(height[low], height[high]) * (high - low));
            if(height[low] < height[high]) {
                low++;
            } else {
                high--;
            }
        }
        return maxWater;
    }
};