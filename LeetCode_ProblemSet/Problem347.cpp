#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        std::vector<int> answer(k);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        for (int num : nums) {
            freq[num]++;
        }
        for (auto p : freq) {
            if (pq.size() < k) {
                pq.push({p.second, p.first});
                continue;
            }
            if (p.second > pq.top().first) {
                pq.push({p.second, p.first});
                pq.pop();
            }
        }
        for (int i = 0; i < k; i++) {
            answer[i] = pq.top().second;
            pq.pop();
        }
        return answer;
    }
};