#include <vector>


class Solution {
public:
    std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {
        std::vector<int> cnt = std::vector<int>(A.size(), 0), C = std::vector<int>(A.size(), 0);

        for (int i = 0; i < A.size(); i++) {
            cnt[A[i] - 1]++;
            cnt[B[i] - 1]++;

            if (i != 0) C[i] = C[i - 1];
            if (cnt[A[i] - 1] == 2) C[i]++;
            if (cnt[B[i] - 1] == 2) C[i]++;
            if (A[i] == B[i]) C[i]--;
        }
        
        return C;
    }
};