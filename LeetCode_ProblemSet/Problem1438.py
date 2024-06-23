import heapq


class Solution(object):
    def longestSubarray(self, nums, limit):
        """
        :type nums: List[int]
        :type limit: int
        :rtype: int
        """
        min_heap, max_heap = [], []
        max_len, left = 0, 0
        
        for i in range(len(nums)):
            heapq.heappush(min_heap, (nums[i], i))
            heapq.heappush(max_heap, (-nums[i], i))
            
            if abs(min_heap[0][0] + max_heap[0][0]) <= limit:
                max_len = max(max_len, i - left + 1)
                
            else:
                left = min(max_heap[0][1], min_heap[0][1]) + 1
                
                while max_heap[0][1] < left:
                    heapq.heappop(max_heap)
                    
                while min_heap[0][1] < left:
                    heapq.heappop(min_heap)
                    
        return max_len