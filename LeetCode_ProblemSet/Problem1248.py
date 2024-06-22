class Solution(object):
    def numberOfSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        even_odd = [0 if num % 2 == 0 else 1 for num in nums]
        sum, prefix_sum = 0, []
        sum_count = {count: 0 for count in range(1, len(nums) + 1)}
        sum_count[0] = 1
        
        for i in range(len(even_odd)):
            sum += even_odd[i]
            prefix_sum.append(sum)
            sum_count[sum] = sum_count[sum] + 1
        
        count = 0
        for num in prefix_sum:
            if 0 <= (num - k) <= sum:
                count += sum_count[num - k]
        
        return count