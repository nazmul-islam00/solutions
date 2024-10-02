#include <vector>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::vector<int> count(26, 0);
        int maxFreq = 0;
        int maxFreqCnt = 0;
        for (char task : tasks) {
            count[task - 'A']++;
            maxFreq = std::max(maxFreq, count[task - 'A']);
        }
        for (int cnt : count) {
            maxFreqCnt += cnt == maxFreq;
        }
        return std::max((n + 1) * (maxFreq - 1) + maxFreqCnt, int(tasks.size()));
    }
};