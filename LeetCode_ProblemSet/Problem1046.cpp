#include <vector>
#include <queue>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        if (stones.size() == 1) {
            return stones[0];
        }
        std::priority_queue<int> heap(stones.begin(), stones.end());
        while (heap.size() > 1) {
            int y = heap.top();
            heap.pop();
            int x = heap.top();
            heap.pop();
            if (x < y) {
                heap.push(y - x);
            } 
        }
        return heap.size() == 1 ? heap.top() : 0;
    }
};