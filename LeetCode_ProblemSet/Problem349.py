class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        nums2 = {num: 1 for num in nums2}
        intersection = {}
        for num in nums1:
            if num in nums2:
                intersection[num] = True
        return [num for num in intersection]