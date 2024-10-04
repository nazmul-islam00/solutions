#include <vector>
#include <queue>
#include <string>
#include <functional>

class Solution {
public:
    std::string kthLargestNumber(std::vector<std::string>& nums, int k) {
        std::priority_queue<std::string, std::vector<std::string>, std::function<bool(const std::string&, const std::string&)>> heap(
            [](const std::string& s1, const std::string& s2) {
                if (s1.length() == s2.length()) {
                    return s1 > s2;
                }
                return s1.length() > s2.length();
            }
        );
        for (const std::string& num : nums) {
            heap.push(num);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        return heap.top();
    }
};