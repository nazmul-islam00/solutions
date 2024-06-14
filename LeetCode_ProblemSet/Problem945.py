class Solution(object):
    def minIncrementForUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        steps = 0
        _max = max(nums)
        
        freq = [0] * (_max + 1 + len(nums))
        
        for num in nums:
            freq[num] += 1
            
        for i in range(len(freq)):
            if freq[i] > 1:
                steps += freq[i] - 1
                freq[i + 1] += freq[i] - 1
                
        return steps