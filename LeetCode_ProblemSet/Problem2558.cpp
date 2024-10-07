#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

class Solution {
public:
    long long pickGifts(std::vector<int>& gifts, int k) {
        long long answer = 0;
        std::priority_queue<int> heap(gifts.begin(), gifts.end());

        for (int i = 0; i < k; i++) {
            int sqrt = (int)std::floor(std::sqrt(heap.top()));
            heap.pop();
            heap.push(sqrt);
        }

        for (int i = 0; i < gifts.size(); i++) {
            answer += heap.top();
            heap.pop();
        }

        return answer;
    }
};