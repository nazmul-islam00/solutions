from functools import cmp_to_key

class Solution:
    def compare(self, num1, num2):
        return int(num1 + num2) - int(num2 + num1)

    def largestNumber(self, nums):
        nums = [str(num) for num in nums]
        nums = sorted(
            nums,
            key=cmp_to_key(self.compare),
            reverse=True
        )
        num = "".join(nums)
        return "0" if int(num) == 0 else num