#include <vector>
#include <queue>
#include <functional>

class Solution {
public:
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        int cur = INT32_MIN;
        int rank = 0;
        std::priority_queue<
            std::pair<int, int>, 
            std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>
        > heap;
        for (int i = 0; i < arr.size(); i++) {
            heap.push({arr[i], i});
        }
        
        while (!heap.empty()) {
            std::pair<int, int> p = heap.top();
            heap.pop();

            if (p.first == cur) {
                arr[p.second] = rank;
            } else {
                arr[p.second] = ++rank;
                cur = p.first;
            }
        }
        return arr;
    }
};