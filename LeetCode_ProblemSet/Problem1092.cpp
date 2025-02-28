#include <string>
#include <vector>

class Solution {
   public:
    std::string shortestCommonSupersequence(std::string str1, std::string str2) {
        int m = str1.size(), n = str2.size();
        std::vector<std::vector<int>> lcs(m + 1, std::vector<int>(n + 1, 0));
        std::string answer = "";

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1])
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                else
                    lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }

        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                answer = (str1[i - 1] = str2[j - 1]) + answer;
                i--;
                j--;
            } else if (lcs[i - 1][j] > lcs[i][j - 1]) {
                answer = str1[i - 1] + answer;
                i--;
            } else {
                answer = str2[j - 1] + answer;
                j--;
            }
        }

        if (i > 0)
            answer = str1.substr(0, i) + answer;
        else if (j > 0)
            answer = str2.substr(0, j) + answer;

        return answer;
    }
};