#include <functional>
#include <queue>
#include <vector>

class Solution {
   public:
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
        std::priority_queue<int> maxHeap;

        for (int i = 0; i < profits.size(); i++) {
            minHeap.push({capital[i], profits[i]});
        }

        for (int projects_done = 0; projects_done < k; projects_done++) {
            while (!minHeap.empty() && minHeap.top().first <= w) {
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }

            if (maxHeap.empty()) {
                break;
            }

            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};