#include <vector>
#include <algorithm>
#include <string>

class Solution {
    int INF;
    std::vector<std::vector<int>> distV;
    std::vector<std::vector<int>> dpV;
    int dist(int currInd, int nextInd, int ringLen) {
        if(this->distV[currInd][nextInd] != -1) 
            return this->distV[currInd][nextInd];
        return this->distV[currInd][nextInd] = std::min(abs(currInd - nextInd), ringLen - abs(currInd - nextInd));
    }
    int dp(int ringInd, int keyInd, std::string ring, std::string key, int minStep) {
        if(keyInd == key.length()) 
            return 0;
        if(this->dpV[ringInd][keyInd] != -1) 
            return this->dpV[ringInd][keyInd];
        for(int i = 0; i < ring.length(); i++) {
            if(ring[i] == key[keyInd]) {
                int steps = dist(ringInd, i, ring.length()) + 1 + dp(i, keyInd + 1, ring, key, INF);
                minStep = std::min(steps, minStep);
            }
        }
        return this->dpV[ringInd][keyInd] = minStep;
    }
public:
    Solution() {
        this->INF = 1e9;
        for(int i = 0; i < 101; i++) {
            this->distV.push_back(std::vector<int> (101, -1));
            this->dpV.push_back(std::vector<int> (101, -1));
        }
    }
    int findRotateSteps(std::string ring, std::string key) {
        return dp(0, 0, ring, key, INF);
    }
};