class Solution(object):
    def minKBitFlips(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        flipped_ind, count = [], 0
        
        for i in range(len(nums)):
            # if the first flipped index is out of range, discard
            if len(flipped_ind) != 0 and flipped_ind[0] + k <= i:
                flipped_ind = flipped_ind[1:]
            
            # parity of flips
            flipped = True if len(flipped_ind) % 2 == 1 else False
            
            if (not flipped and nums[i] == 0) or(flipped and nums[i] == 1):
                # if flips are possible
                if i < len(nums) - k + 1:
                    flipped_ind.append(i)
                    count += 1
                    
                else:
                    return -1
            
        return count      