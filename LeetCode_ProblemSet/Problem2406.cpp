#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int minGroups(std::vector<std::vector<int>>& intervals) {
        std::vector<std::pair<int, int>> events;
        events.reserve(2 * intervals.size());

        for (const std::vector<int>& interval : intervals) {
            events.emplace_back(interval[0], 1);
            events.emplace_back(interval[1] + 1,- 1);
        }

        std::sort(events.begin(), events.end());

        int prefix = 0, maxPrefix = 0;

        for (const std::pair<int, int>& event : events) {
            prefix += event.second;
            maxPrefix = std::max(maxPrefix, prefix);
        }

        return maxPrefix;
    }
};