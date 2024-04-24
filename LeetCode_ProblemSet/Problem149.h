#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm>

class Solution {
    //*slope for lines parallel to y-axis
    double INF = 1e9;
    /*
    * y = mx + c
    * returns the slope, m & y intercept,c
    * return value: {m, c}
    */
    std::pair<double, double> getSlope(std::vector<int>& p1, std::vector<int>& p2) {
        if(p1[0] == p2[0]) {
            return {this->INF, 0};
        }
       double slope = (double)(p2[1] - p1[1]) / (double)(p2[0] - p1[0]);
       double c = (double)p1[1] - (double)p1[0] * slope;
       return {slope, c};
    }
public:
    int maxPoints(std::vector<std::vector<int>>& points) {
        //* base case
        if(points.size() == 1) {
            return 1;
        }
        /*
        * slopeMap: map to store maps for different slopes 
        * the maps for different slopes store maps for different values of y intercepts
        * the maps for different values of y intercepts store the indices of the points
        * structure: {slope, {y intercept, {point_index, 1}}
        */
        std::unordered_map<double, std::unordered_map<double, std::unordered_map<int, int>>> slopeMap;
        //* vector to store the unique slopes
        std::vector<double> slopes;
        /*
        * infSlopeMap: map to store maps for different x values
        * the maps for different x values store the indices of the points with that particular x value and INF slope
        * structure: {x, {point_index, 1}}
        */
        std::unordered_map<int, std::unordered_map<int, int>> infSlopeMap;
        //* for each pair find slope and y intercept
        for(int i = 0; i < points.size(); i++) {
            for(int j = i + 1; j < points.size(); j++) {
                std::pair<double, double> slopeRes = getSlope(points[i], points[j]);
                double slope = slopeRes.first;
                double c = slopeRes.second;
                //* if slope is INF the store in the infSlopeMap according to the x value
                if(slope == this->INF) {
                    int x = points[i][0];
                    auto it1 = infSlopeMap.find(x);
                    //* if that x value is not present in the map then add it
                    if(it1 == infSlopeMap.end()) {
                        std::unordered_map<int, int> tempMap;
                        tempMap[i] = 1;
                        tempMap[j] = 1;
                        infSlopeMap[x] = tempMap;
                    } else {
                        auto tempMap = it1->second;
                        auto it2 = it1->second.find(i);
                        auto it3 = it1->second.find(j);
                        //* add to that x value map if the indices are not already present
                        if(it2 == tempMap.end()) {
                            tempMap[i] = 1;
                        }
                        if(it3 == tempMap.end()) {
                            tempMap[j] = 1;
                        }
                        it1->second = tempMap;
                    }
                    continue;
                }
                auto it = slopeMap.find(slope);
                //* if slope is already not present, add it
                if(it == slopeMap.end()) {
                    slopes.push_back(slope);
                    //* cMap: map for the particular y intercept
                    std::unordered_map<int, int> cMap;
                    //* tempMap: map for the particular slope
                    std::unordered_map<double, std::unordered_map<int, int>> tempMap;
                    cMap[i] = 1;
                    cMap[j] = 1;
                    tempMap[c] = cMap;
                    slopeMap[slope] = tempMap;
                } else {
                    auto tempMap = it->second;
                    auto it1 = tempMap.find(c);
                    //* search for the particular y intercept
                    if(it1 == tempMap.end()) {
                        std::unordered_map<int ,int> cMap;
                        cMap[i] = 1;
                        cMap[j] = 1;
                        tempMap[c] = cMap;
                    } else {
                        auto cMap = it1->second;
                        auto it2 = cMap.find(i);
                        auto it3 = cMap.find(j);
                        //* check if the indices are already present
                        if(it2 == cMap.end()) {
                            cMap[i] = 1;
                        }
                        if(it3 == cMap.end()) {
                            cMap[j] = 1;
                        }
                        it1->second = cMap;
                    }
                    it->second = tempMap;
                }
            }
        }
        int maxPoints = 0;
        //* iterate through the maps & compare the sizes
        for(double i : slopes) {
            auto it = slopeMap.find(i);
            auto tempMap = it->second;
            for(auto j : tempMap) {
                auto cMap = j.second;
                maxPoints = std::max(maxPoints, (int)cMap.size());
            }
        }
        for(auto i : infSlopeMap) {
            auto it = i.second;
            maxPoints = std::max(maxPoints, (int)it.size());
        }
        return maxPoints;
    }
};