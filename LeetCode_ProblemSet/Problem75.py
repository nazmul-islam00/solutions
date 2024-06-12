class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        cur, low, high = 0, 0, len(nums) - 1

        while cur <= high:
            # if cur is 2 and not the same as high, swap and decrease high
            if nums[cur] == 2 and cur != high:
                nums[cur], nums[high] = nums[high], nums[cur]
                high -= 1
            
            # if cur is 0 and not the same as low, swap and increase low
            elif nums[cur] == 0 and cur != low:
                nums[cur], nums[low] = nums[low], nums[cur]
                low += 1

            # if cur is 1, leave it as it is and increase cur
            else:
                cur += 1