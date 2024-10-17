#include <vector>
#include <iostream>

class Solution {
public:
    int maximumSwap(int num) {
        std::vector<int> digits;
        digits.reserve(9);
        bool swap = false;
        int _max = -1;
        int pos = -1;

        while (num >= 1) {
            int digit = num % 10;

            if (digit < _max) {
                swap = true;
                pos = digits.size();
            } else {
                _max = digit;
            }

            digits.emplace_back(digit);
            num /= 10;
        }

        if (swap) {
            int swap_max = -1, swap_pos = -1;

            for (int i = 0; i < pos; i++) {
                if (digits[i] > swap_max) {
                    swap_max = digits[i];
                    swap_pos = i;
                }
            }

            digits[swap_pos] = digits[pos];
            digits[pos] = swap_max;
        }

        int ans = 0, mul = 1;
        for (int digit : digits) {
            ans += mul * digit;
            mul *= 10;
        }

        return ans;
    }
};