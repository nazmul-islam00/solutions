#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int num : nums) {
            if (pq.size() < k) {
                pq.push(num);
                continue;
            }
            if (num > pq.top()) {
                pq.push(num);
                pq.pop();
            }
        }
        return pq.top();
    }
};