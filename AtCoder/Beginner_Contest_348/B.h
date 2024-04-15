//
// Created by HP on 4/15/2024.
//

#ifndef B_H
#define B_H
#include <cmath>
#include <iostream>
#include <vector>


class Solution {
    double getDistance(std::pair<int, int> point1, std::pair<int, int> point2) {
        return std::sqrt(pow(point1.first - point2.first, 2) + pow(point1.second - point2.second, 2));
    }
public:
    void run() {
        int n;
        std::cin >> n;
        std::vector<std::pair<int, int>> points(n, {0, 0});
        for(int i = 0; i < n; i++)
            std::cin >> points[i].first >> points[i].second;
        for(int i = 0; i < n; i++) {
            double maxDistance = 0;
            int maxDistanceIndex = -1;
            for(int j = 0; j < n; j++) {
                double distance = getDistance(points[i], points[j]);
                if(distance > maxDistance) {
                    maxDistance = distance;
                    maxDistanceIndex = j + 1;
                }
            }
            std::cout << maxDistanceIndex << std::endl;
        }
    }
};



#endif //B_H
