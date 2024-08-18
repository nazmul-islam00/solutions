class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        # avoid duplicates
        uglyNumbers = set([1])
        for idx in range(n):
            # find min ugly
            ugly = min(uglyNumbers)
            uglyNumbers.remove(ugly)
            uglyNumbers.add(ugly * 2)
            uglyNumbers.add(ugly * 3)
            uglyNumbers.add(ugly * 5)
            
        return ugly
            