#include <vector>
#include <algorithm>

class Solution {
    public:
    long long putMarbles(std::vector<int>& weights, int k) {
        std::vector<int> costs(weights.size() - 1);
        for (int idx = 0; idx < weights.size() - 1; idx++) {
            costs[idx] = weights[idx] + weights[idx + 1];
        }
        std::sort(costs.begin(), costs.end());

        long long answer = 0;
        for (int i = 0; i < k - 1; i++) {
            answer += costs[costs.size() - 1 - i] - costs[i]; 
        }
        return answer;
    }
};