class Solution(object):
    def construct2DArray(self, original, m, n):
        """
        :type original: List[int]
        :type m: int
        :type n: int
        :rtype: List[List[int]]
        """
        if m * n != len(original):
            return []

        arr = []
        for i in range(m):
            arr.append(original[i * n : (i + 1) * n])
        return arr
        