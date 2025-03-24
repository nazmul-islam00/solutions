#include <vector>
#include <algorithm>


class Solution {
    public:
    int countDays(int days, std::vector<std::vector<int>>& meetings) {
        int curStart = 0, curEnd = 0;
        int count = 0;

        std::sort(meetings.begin(), meetings.end());
        for (const auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            if (curStart <= start && start <= curEnd) {
                curEnd = std::max(curEnd, end);
            } else {
                count += start - curEnd - 1;
                curStart = start, curEnd = end;
            }
        }
        count += days - curEnd;

        return count;
    }
};