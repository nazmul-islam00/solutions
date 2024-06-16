class Solution(object):
    def minPatches(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: int
        """
        sum, idx, count = 0, 0, 0
        
        while sum < n:
            
            if idx < len(nums) and nums[idx] <= (sum + 1):
                sum += nums[idx]
                idx += 1
                
            else:
                sum = 2 * sum + 1
                count += 1
        
        return count
        