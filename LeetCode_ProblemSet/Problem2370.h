#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>

class Solution {
public:
    int longestIdealString(std::string s, int k) {
        int maxLen = 1;
        std::vector<int> dp(s.length(), maxLen);
        std::unordered_map<char, int> lastOccurence;
        lastOccurence[s[0]] = 0;
        for(int i = 1; i < s.length(); i++) {
            int c = s[i];
            for(char j = 'a'; j <= 'z'; j++) {
                if(std::abs(c - j) > k) {
                    continue;
                }
                if(lastOccurence.find(j) == lastOccurence.end()) {
                    continue;
                }
                dp[i] = std::max(dp[i], dp[lastOccurence.find(j)->second] + 1);
            }
            lastOccurence[c] = i;
            maxLen = std::max(maxLen, dp[i]);
        }
        return maxLen;
    }
};