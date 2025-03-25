#include <algorithm>
#include <vector>
#include <functional>

class Solution {
   public:
    bool checkValidCuts(int n, std::vector<std::vector<int>>& rectangles) {
        for (int i = 0; i < 2; i++) {
            std::vector<std::pair<int, int>> coords;
            coords.reserve(rectangles.size());

            for (const auto& r : rectangles) {
                coords.emplace_back(r[i], r[i + 2]);
            }

            std::sort(coords.begin(), coords.end());

            int cnt = 0, cur = 0;
            for (const auto& p : coords) {
                int start = p.first, end = p.second;

                if (start < cur) {
                    cur = std::max(cur, end);
                    continue;
                }
                cnt++;
                if (cnt == 3) return true;
                cur = end;
            }
        }

        return false;
    }
};