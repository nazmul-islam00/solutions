#include <vector>
#include <queue>
#include <algorithm>


class Solution {
private:
    int maxSumOfDigit = 81;

public:
    int maximumSum(std::vector<int>& nums) {
        std::vector<std::priority_queue<int, std::vector<int>, std::greater<int>>> sets = std::vector<std::priority_queue<int, std::vector<int>, std::greater<int>>>(maxSumOfDigit + 1);
        int result = -1;

        for (int num : nums) {
            int sumOfDigits = getSumOfDigits(num);
            sets[sumOfDigits].push(num);
            if (sets[sumOfDigits].size() > 2) sets[sumOfDigits].pop();
        }

        for (auto& set : sets) {
            if (set.size() < 2) continue;
            int num1 = set.top();
            set.pop();
            result = std::max(result, num1 + set.top());
        }

        return result;
}

private:
    int getSumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};