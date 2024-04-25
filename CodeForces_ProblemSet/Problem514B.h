#include <vector>
#include <iostream>
#include <functional>
#include <unordered_map>

class Solution {
    double INF = 1e9;
    double getSlope(std::pair<int, int> p1, std::pair<int, int> p2) {
        if(p1.first == p2.first) {
            return this->INF;
        }
        return (double)(p2.second - p1.second) / (double)(p2.first - p1.first);
    }
public:
    void run() {
        int n;
        std::cin >> n;
        std::pair<int, int> lazerGun;
        std::cin >> lazerGun.first >> lazerGun.second;
        std::vector<std::pair<int, int>> stormTroopers(n);
        for(int i = 0; i < n; i++) {
            std::cin >> stormTroopers[i].first >> stormTroopers[i].second;
        }
        std::unordered_map<double, int> slopeMap;
        for(int i = 0; i < stormTroopers.size(); i++) {
            double slope = getSlope(lazerGun, stormTroopers[i]);
            if(slopeMap.find(slope) == slopeMap.end()) {
                slopeMap[slope] = 1;
            }
        }
        std::cout << slopeMap.size() << std::endl;
    }
};