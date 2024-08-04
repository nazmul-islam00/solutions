class Solution(object):
    def rangeSum(self, nums, n, left, right):
        """
        :type nums: List[int]
        :type n: int
        :type left: int
        :type right: int
        :rtype: int
        """
        prefix_sums = [0] * (n + 1)
        prefix_sum = 0
        
        for i in range(n):
            prefix_sum += nums[i]
            prefix_sums[i + 1] = prefix_sum
        
        
        subarray_sums = []
    
        for i in range(n):
            for j in range(i, n):
                subarray_sums += [prefix_sums[j + 1] - prefix_sums[i]]
                
        subarray_sums = sorted(subarray_sums)
        ans = 0
        
        for i in range(left - 1, right):
            ans = (ans + subarray_sums[i]) % (1e9 + 7)
        
        return ans
        