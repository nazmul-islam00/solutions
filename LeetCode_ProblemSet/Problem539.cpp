#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int findMinDifference(std::vector<std::string>& timePoints) {
        std::vector<int> time(timePoints.size());
        for (int i = 0; i < timePoints.size(); i++) {
            int hour = (timePoints[i][0] - '0') * 10 + timePoints[i][1] - '0';
            int minute = (timePoints[i][3] - '0') * 10 + timePoints[i][4] - '0';
            time[i] = hour * 60 + minute;
        }
        std::sort(time.begin(), time.end());
        int minDiff = 1440 - time[time.size() - 1] + time[0];
        for (int i = 0; i < time.size() - 1; i++) {
            minDiff = std::min(minDiff, time[i + 1] - time[i]);
        }
        return minDiff;
    }
};