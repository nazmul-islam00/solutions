#include <vector>
#include <unordered_set>


class Solution {
public:
    int lenLongestFibSubseq(std::vector<int>& arr) {
        std::unordered_set<int> set(arr.begin(), arr.end());
        int maxLen = 0;

        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int num1 = arr[i], num2 = arr[j];
                int len = 2;

                while (true) {
                    int num3 = num1 + num2;
                    if (set.find(num3) != set.end()) {
                        num1 = num2;
                        num2 = num3;
                        len++;
                    } else {
                        break;
                    }
                }

                if (len >= 3) maxLen = std::max(maxLen, len);
            }
        }

        return maxLen;
    }
};