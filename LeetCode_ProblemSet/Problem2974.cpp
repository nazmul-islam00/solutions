#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> numberGame(std::vector<int>& nums) {
        std::vector<int> answer(nums.size());
        std::priority_queue<int, std::vector<int>, std::greater<int>> heap(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() / 2; i++) {
            answer[2 * i + 1] = heap.top();
            heap.pop();
            answer[2 * i] = heap.top();
            heap.pop();
        }

        return answer;
    }
};