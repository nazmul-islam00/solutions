#include <vector>
#include <queue>
#include <cmath>

class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        long long ans = 0;
        std::priority_queue<int> pq(nums.begin(), nums.end());

        while (k--) {
            int top = pq.top();
            pq.pop();
            ans += top;
            pq.push((int)std::ceil(top / 3.0));
        }

        return ans;
    }   
};