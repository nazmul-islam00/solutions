#include <vector>


class Solution {
   private:
    int mod = 1e9 + 7;

   public:
    int numOfSubarrays(std::vector<int>& arr) {
        int evenCount = 1, oddCount = 0, answer = 0;
        bool evenSum = true;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] % 2) evenSum = !evenSum;

            if (evenSum) {
                evenCount++;
                answer = (answer + oddCount) % mod;
            } else {
                oddCount++;
                answer = (answer + evenCount) % mod;
            }
        }

        return answer;
    }
};