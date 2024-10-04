#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

class Solution {
public:
    std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
        std::priority_queue<std::pair<int, int>> heap;
        std::vector<int> answer(k);
        for (int i = 0; i < mat.size(); i++) {
            heap.push({std::accumulate(mat[i].begin(), mat[i].end(), 0), i});
            if (heap.size() > k) {
                heap.pop();
            }
        }
        for (int i = 0; i < k; i++) {
            answer[k - 1 - i] = heap.top().second;
            heap.pop();
        }
        return answer;
    }
};