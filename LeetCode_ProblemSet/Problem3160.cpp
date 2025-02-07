#include <vector>
#include <unordered_map>


class Solution {
public:
    std::vector<int> queryResults(int limit, std::vector<std::vector<int>>& queries) {
        std::unordered_map<int, int> colors, colorCount;
        std::vector<int> result(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            int ball = queries[i][0], color = queries[i][1];

            if (colors.find(ball) == colors.end()) {
                colors[ball] = color;
                if (colorCount.find(color) == colorCount.end()) colorCount[color] = 1;
                else colorCount[color]++;
            } else {
                if (colorCount[colors[ball]] == 1) colorCount.erase(colors[ball]);
                else colorCount[colors[ball]]--;

                colors[ball] = color;
                if (colorCount.find(color) == colorCount.end()) colorCount[color] = 1;
                else colorCount[color]++;
            }

            result[i] = colorCount.size();
        }

        return result;
    }
};