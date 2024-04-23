#include <vector>

class Solution {
    int INF = 1e9;
    double getSlope(std::vector<int>& p1, std::vector<int>& p2) {
        if(p1[0] == p2[0]) {
            return INF;
        }
        return (double)(p2[1] - p1[1]) / (double)(p2[0] - p1[0]);
    }
public:
    bool checkStraightLine(std::vector<std::vector<int>>& coordinates) {
        double slope = getSlope(coordinates[0], coordinates[1]);
        for(int i = 1; i < coordinates.size() - 1; i++) {
            if(slope != getSlope(coordinates[i], coordinates[i + 1])) {
                return false;
            }
        }
        return true;
    }
};