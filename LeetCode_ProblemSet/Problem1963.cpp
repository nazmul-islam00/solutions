#include <string>

class Solution {
public:
    int minSwaps(std::string s) {
        int openCnt = 0, closeCnt = 0, swaps = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[') {
                openCnt++;
            } else {
                closeCnt++;
            }
            if (closeCnt > openCnt) {
                swaps++;
                openCnt++;
                closeCnt--;
            }
        }
        return swaps;
    }
};