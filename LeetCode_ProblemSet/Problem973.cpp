#include <vector>
#include <queue>
#include <functional>

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        std::priority_queue<std::pair<int, int>> heap;
        for (int i = 0; i < points.size(); i++) {
            heap.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
            if (heap.size() > k) {
                heap.pop();
            }
        }

        std::vector<std::vector<int>> answer;
        answer.reserve(k);
        for (int i = 0; i < k; i++) {
            answer.emplace_back(points[heap.top().second]);
            heap.pop();
        }
        return answer;
    }
};