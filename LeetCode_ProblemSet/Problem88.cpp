#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        std::vector<int> merged = std::vector<int>(m + n);
        int idx = 0, idx1 = 0, idx2 = 0;

        while (idx1 < m && idx2 < n) {
            merged[idx++] = (nums1[idx1] < nums2[idx2]) ? nums1[idx1++] : nums2[idx2++];
        }
        while (idx1 < m) {
            merged[idx++] = nums1[idx1++];
        }
        while (idx2 < n) {
            merged[idx++] = nums2[idx2++];
        }

        nums1 = merged;
    }
};