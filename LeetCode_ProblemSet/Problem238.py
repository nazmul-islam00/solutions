class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        prefixProduct = [1 for _ in range(len(nums))]
        suffixProduct = [1 for _ in range(len(nums))]
        
        for i in range(1, len(nums)):
            prefixProduct[i] = prefixProduct[i - 1] * nums[i - 1]
            
        for i in range(len(nums) - 2, -1, -1):
            suffixProduct[i] = suffixProduct[i + 1] * nums[i + 1]
            
        return [suffixProduct[i] * prefixProduct[i] for i in range(len(nums))]