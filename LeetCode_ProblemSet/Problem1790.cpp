#include <string>


class Solution {
public:
    bool areAlmostEqual(std::string s1, std::string s2) {
        int idx1 = -1, idx2 = -1;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i]) continue;
            if (idx1 == -1) idx1 = i;
            else if (idx2 == -1) idx2 = i;
            else return false;
        }
        if (idx1 == -1 && idx2 == -1) return true;
        if (idx1 == -1 || idx2 == -1) return false;
        return s1[idx1] == s2[idx2] && s1[idx2] == s2[idx1];
    }
};