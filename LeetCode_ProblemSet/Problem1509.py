import math

class Solution(object):
    def minDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 4:
            return 0
        
        nums = sorted(nums)
        difference = nums[len(nums) - 4] - nums[0]
        left, right = 1, len(nums) - 3
        for _ in range(3):
            difference = min(difference, nums[right] - nums[left])
            left, right = left + 1, right + 1
            
        return difference