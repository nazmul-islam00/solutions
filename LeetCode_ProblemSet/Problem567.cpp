#include <string>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        
        int* target = new int[26];
        std::memset(target, 0, 26 * sizeof(int));
        for (int i = 0; i < s1.length(); i++) {
            target[s1[i] - 'a']++;
        }

        int* freq = new int[26];
        std::memset(freq, 0, 26 * sizeof(int));
        for (int i = 0; i < s1.length(); i++) {
            freq[s2[i] - 'a']++;
        }
        bool flag = true;
        for (int i = 0; i < 26; i++) {
            if (target[i] != freq[i]) {
                flag = false;
            }
        }
        if (flag) {
            return true;
        }

        for (int i = 0; i < s2.length() - s1.length(); i++) {
            freq[s2[i] - 'a']--;
            freq[s2[s1.length() + i] - 'a']++;
            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (target[i] != freq[i]) {
                    flag = false;
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }
};