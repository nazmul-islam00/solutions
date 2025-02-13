#include <vector>
#include <queue>
#include <algorithm>


class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> heap(nums.begin(), nums.end());
        int ops = 0;

        while (nums.size() >= 2) {
            if (heap.top() >= k) break;
            int num1 = heap.top(); heap.pop();
            int num2 = heap.top(); heap.pop();
            long long num = (long long) std::min(num1, num2) * 2 + std::max(num1, num2);
            heap.push((num >= k) ? k : (int) num);
            ops++;
        }

        return ops;
    }
};