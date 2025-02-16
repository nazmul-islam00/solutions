#include <vector>
#include <iostream>


class Solution {
public:
    std::vector<int> constructDistancedSequence(int n) {
        if (n == 1) return {1};

        std::vector<int> answer(2 * n - 1, -1);
        answer[0] = answer[n] = n;
        int used = 0 | (1 << n);

        place(answer, 1, n, used);

        return answer;
    }

private: 
    bool place(std::vector<int>& answer, int pos, int n, int used) {
        if (pos == answer.size()) return true;
        if (used == ((1 << (n + 1)) - 1)) return true;

        for (int i = n; i > 0; i--) {
            if ((used & (1 << i)) != 0) continue;

            if (i == 1) {
                answer[pos] = 1;
                used |= 2;

                int newPos = pos;
                while (newPos < answer.size() && answer[newPos] != -1) {
                    newPos++;
                }
                if (place(answer, newPos, n, used)) {
                    return true;
                } else {
                    used ^= (1 << i);
                    answer[pos] = -1;
                }
            }

            else if ((pos + i) < answer.size() && answer[pos + i] == -1) {
                answer[pos] = answer[pos + i] = i;
                used |= (1 << i);

                int newPos = pos;
                while (newPos < answer.size() && answer[newPos] != -1) {
                    newPos++;
                }
                if (place(answer, newPos, n, used)) {
                    return true;
                } else {
                    used ^= (1 << i);
                    answer[pos] = answer[pos + i] = -1;
                }
            } 
        }

        return false;
    }
};
