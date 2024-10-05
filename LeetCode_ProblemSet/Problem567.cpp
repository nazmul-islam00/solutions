#include <string>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        int target[26];
        std::memset(target, 0, 26 * sizeof(int));
        for (int i = 0; i < s1.length(); i++) {
            target[s1[i] - 'a']++;
        }

        int freq[26];
        std::memset(freq, 0, 26 * sizeof(int));
        for (int i = 0; i < s1.length(); i++) {
            freq[s2[i] - 'a']++;
        }
        if (std::memcmp(target, freq, 26 * sizeof(int)) == 0) {
            return true;
        }

        for (int i = 0; i < s2.length() - s1.length(); i++) {
            freq[s2[i] - 'a']--;
            freq[s2[s1.length() + i] - 'a']++;
            if (std::memcmp(target, freq, 26 * sizeof(int)) == 0) {
                return true;
            }
        }
        return false;
    }
};