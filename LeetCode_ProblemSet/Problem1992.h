#include <vector>

class Solution {
    void getLand(std::vector<std::vector<int>>& land, std::vector<std::vector<int>>& answer, std::vector<std::vector<bool>>& visited, int startX, int startY) {
        int endX = startX, endY = startY;
        while(endX + 1 < land.size() && land[endX + 1][endY])
            endX++;
        while(endY + 1 < land[0].size() && land[endX][endY + 1])
            endY++;
        for(int i = startX; i <= endX; i++)
            for(int j = startY; j <= endY; j++)
                visited[i][j] = true;
        answer.push_back({startX, startY, endX, endY});
    }
public:
    std::vector<std::vector<int>> findFarmland(std::vector<std::vector<int>>& land) {
        std::vector<std::vector<bool>> visited (land.size(), std::vector<bool> (land[0].size(), false));
        std::vector<std::vector<int>> answer;
        for(int i = 0; i < land.size(); i++)
            for(int j = 0; j < land[0].size(); j++)
                if(land[i][j] && !visited[i][j])
                    getLand(land, answer, visited, i, j);
        return answer;
    }
};