#include <vector>
#include <queue>
#include <algorithm>


class Solution {
public:
    int maximumInvitations(std::vector<int>& favorite) {
        std::vector<int> inDegree(favorite.size(), 0), depth(favorite.size(), 1);
        std::queue<int> bfsQueue;

        for (int fav : favorite) inDegree[fav]++;
        for (int i = 0; i < favorite.size(); i++) {
            if (inDegree[i] == 0) bfsQueue.push(i);
        }

        while (!bfsQueue.empty()) {
            int curr = bfsQueue.front(); bfsQueue.pop();
            int next = favorite[curr];
            depth[next] = std::max(depth[next], depth[curr] + 1);
            inDegree[next]--;
            if (inDegree[next] == 0) bfsQueue.push(next);
        }

        int maxCycleLength = 0, maxAcyclicChainLength = 0;
        for (int i = 0; i < favorite.size(); i++) {
            if (inDegree[i] == 0) continue;
            int curr = i, length = 0;
            
            while (inDegree[curr] != 0) {
                inDegree[curr] = 0;
                length++;
                curr = favorite[curr];
            }

            if (length == 2) maxAcyclicChainLength += depth[i] + depth[favorite[i]];
            else maxCycleLength = std::max(maxCycleLength, length);
        }

        return std::max(maxAcyclicChainLength, maxCycleLength);
    }
};