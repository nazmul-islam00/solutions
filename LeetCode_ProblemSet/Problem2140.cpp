#include <vector>
#include <iostream>

class Solution {
   private:
    std::vector<long long> points;

   public:
    long long mostPoints(std::vector<std::vector<int>>& questions) {
        int n = questions.size();
        points = std::vector<long long>(n, -1);
        points[n - 1] = questions[n - 1][0];
        helper(questions, 0);
        for (int i : points) {
            std::cout << i << '\t';
        }
        std::cout << std::endl;
        return points[0];
    }

   private:
    long long helper(const std::vector<std::vector<int>>& questions, const int idx) {
        if (idx >= questions.size()) return 0;
        if (points[idx] != -1) return points[idx];
        return points[idx] = std::max(
            questions[idx][0] + helper(questions, questions[idx][1] + idx + 1),
            helper(questions, idx + 1)
        );
    }
};