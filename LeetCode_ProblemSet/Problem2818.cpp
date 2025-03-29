#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <vector>

class Solution {
   public:
    const int MOD = 1e9 + 7;

    int maximumScore(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> primeScores(n);

        for (int index = 0; index < n; index++) {
            int num = nums[index];

            for (int factor = 2; factor <= sqrt(num); factor++) {
                if (num % factor == 0) {
                    primeScores[index]++;

                    while (num % factor == 0) num /= factor;
                }
            }

            if (num >= 2) primeScores[index]++;
        }

        std::vector<int> nextDominant(n, n);
        std::vector<int> prevDominant(n, -1);

        std::stack<int> decreasingPrimeScoreStack;

        for (int index = 0; index < n; index++) {
            while (!decreasingPrimeScoreStack.empty() && primeScores[decreasingPrimeScoreStack.top()] < primeScores[index]) {
                int topIndex = decreasingPrimeScoreStack.top();
                decreasingPrimeScoreStack.pop();
                nextDominant[topIndex] = index;
            }

            if (!decreasingPrimeScoreStack.empty())
                prevDominant[index] = decreasingPrimeScoreStack.top();

            decreasingPrimeScoreStack.push(index);
        }

        std::vector<long long> numOfSubarrays(n);
        for (int index = 0; index < n; index++) {
            numOfSubarrays[index] = (long long)(nextDominant[index] - index) * (index - prevDominant[index]);
        }

        std::priority_queue<std::pair<int, int>> processingQueue;

        for (int index = 0; index < n; index++)
            processingQueue.push({nums[index], index});

        long long score = 1;

        while (k > 0) {
            auto [num, index] = processingQueue.top();
            processingQueue.pop();

            long long operations = std::min((long long)k, numOfSubarrays[index]);
            score = (score * power(num, operations)) % MOD;
            k -= operations;
        }

        return score;
    }

   private:
    long long power(long long base, long long exponent) {
        long long res = 1;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                res = ((res * base) % MOD);
            }

            base = (base * base) % MOD;
            exponent /= 2;
        }

        return res;
    }
};