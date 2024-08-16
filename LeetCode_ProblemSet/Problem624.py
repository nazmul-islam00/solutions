class Solution(object):
    def maxDistance(self, arrays):
        """
        :type arrays: List[List[int]]
        :rtype: int
        """
        smallest, largest = arrays[0][0], arrays[0][-1]
        max_dist = 0
        for idx in range(1, len(arrays)):
            max_dist = max(
                abs(arrays[idx][-1] - smallest), 
                abs(largest - arrays[idx][0]),
                max_dist
            )
            smallest = min(smallest, arrays[idx][0])
            largest = max(largest, arrays[idx][-1])
        return max_dist