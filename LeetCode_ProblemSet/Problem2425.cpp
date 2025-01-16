#include <vector>


class Solution {
public:
    int xorAllNums(std::vector<int>& nums1, std::vector<int>& nums2) {
        int answer = 0;
        
        if (nums2.size() % 2 != 0) {
            for (const int num : nums1) {
                answer ^= num;
            }
        }
        
        if (nums1.size() % 2 != 0) {
            for (const int num : nums2) {
                answer ^= num;
            }
        }

        return answer;
    }
};