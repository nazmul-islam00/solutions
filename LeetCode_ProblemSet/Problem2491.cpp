#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    long long dividePlayers(std::vector<int>& skill) {
        if (skill.size() == 2) {
            return (long long) skill[0] * skill[1];
        }

        int sum = 0;
        std::unordered_map<int, int> freq;
        for (int s : skill) {
            sum += s;
            freq[s]++;
        }

        if (sum % (skill.size() / 2)) {
            return -1;
        }
        
        int target = sum / (skill.size() / 2);
        long long chemistry = 0;
        for (auto p : freq) {
            int partner = target - p.first;
            if (freq[partner] != p.second) {
                return -1;
            }
            chemistry += (long long) p.first * partner * p.second;
        }
        return chemistry / 2;
    }
};