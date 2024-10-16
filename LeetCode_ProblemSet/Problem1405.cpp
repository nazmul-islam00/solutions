#include <string>

class Solution {
public:
    std::string longestDiverseString(int a, int b, int c) {
        std::string ans = "";
        int total = a + b + c;
        int curA = 0, curB = 0, curC = 0;
        int flag = -1;

        for (int i = 0; i < total; i++) {
            if ((a >= b && a >= c && curA < 2) ||
                (a > 0 && (curB == 2 || curC == 2))) {
                ans += "a";
                a--;
                curA++;
                curB = curC = 0;
            }
            else if ((b >= a && b >= c && curB < 2) ||
                (b > 0 && (curA == 2 || curC == 2))) {
                ans += "b";
                b--;
                curB++;
                curA = curC = 0;
            }
            else if ((c >= b && c >= a && curC < 2) ||
                (c > 0 && (curA == 2 || curB == 2))) {
                ans += "c";
                c--;
                curC++;
                curA = curB = 0;
            }
            else break;
        }
        
        return ans;
    }
};