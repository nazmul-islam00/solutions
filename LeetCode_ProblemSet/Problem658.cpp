#include <vector>
#include <cmath>
#include <queue>
#include <functional>
#include <algorithm>

class Solution {
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - 1;
        
        while (right - left >= k) {
            if (std::abs(arr[left] - x) > std::abs(arr[right] - x)) {
                left++;
            } else {
                right--;
            }
        }
        
        return std::vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};