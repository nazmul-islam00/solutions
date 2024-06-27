class Solution(object):
    def findCenter(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: int
        """
        return edges[0][0] if edges[0][0] in edges[1] else edges[0][1]   