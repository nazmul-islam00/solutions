#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> mergeArrays(std::vector<std::vector<int>>& nums1, std::vector<std::vector<int>>& nums2) {
        std::vector<std::vector<int>> answer;
        answer.reserve(nums1.size() + nums2.size());
        int i = 0, j = 0;

        for (; i < nums1.size() && j < nums2.size();) {
            int id1 = nums1[i][0], val1 = nums1[i][1];
            int id2 = nums2[j][0], val2 = nums2[j][1];

            if (id1 < id2) {
                answer.push_back({id1, val1});
                i++;
            } else if (id2 < id1) {
                answer.push_back({id2, val2});
                j++;
            } else {
                answer.push_back({id1, val1 + val2});
                i++;
                j++;
            }
        }

        while (i < nums1.size()) {
            answer.push_back(nums1[i++]);
        }

        while (j < nums1.size()) {
            answer.push_back(nums2[j++]);
        }

        return answer;
    }
};