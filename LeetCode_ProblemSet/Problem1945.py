class Solution(object):
    def getLucky(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        nums = [0] * 2 * len(s)
        idx = 0
        for ch in s:
            num = ord(ch) - ord("a") + 1
            if num >= 10:
                nums[idx] = int(num / 10)
                idx += 1
            nums[idx] = num % 10
            idx += 1
        for _ in range(k - 1):
            s = str(sum(nums))
            nums = [0] * 2 * len(s)
            idx = 0
            for ch in s:
                num = ord(ch) - ord("0")
                if num >= 10:
                    nums[idx] = int(num / 10)
                    idx += 1
                nums[idx] = num % 10
                idx += 1
        return sum(nums)