#include <string>

class Solution {
   public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;

        for (int num = low; num <= high; num++) {
            std::string s = std::to_string(num);
            if (s.length() % 2 == 1) continue;

            int sum = 0;
            for (int idx = 0; idx < s.length() / 2; idx++) {
                sum += s[idx];
            }
            for (int idx = s.length() / 2; idx < s.length(); idx++) {
                sum -= s[idx];
            }
            cnt += sum == 0;
        }

        return cnt;
    }
};