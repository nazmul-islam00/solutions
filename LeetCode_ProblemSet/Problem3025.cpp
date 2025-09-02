#include <vector>

class Solution {
public:
    int numberOfPairs(std::vector<std::vector<int>>& points) {
        int cnt = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if (y1 < y2 || x1 > x2) continue;
                bool flag = false;
                for (int k = 0; k < points.size(); k++) {
                    if (k == i || k == j) continue;
                    int x = points[k][0], y = points[k][1];
                    if (x1 <= x && x <= x2 && y2 <= y && y <= y1) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) cnt++;
            }
        }
        return cnt;
    }
};