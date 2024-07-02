from collections import Counter

class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        count1 = Counter(nums1)
        count2 = Counter(nums2)
        ans = []

        for key in count1.keys():
            ans += [key] * min(count1[key], count2[key])
            
        return ans