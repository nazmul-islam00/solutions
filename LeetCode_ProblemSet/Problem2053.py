class Solution(object):
    def kthDistinct(self, arr, k):
        """
        :type arr: List[str]
        :type k: int
        :rtype: str
        """
        map = {}
        for str in arr:
            if str in map:
                map[str] = False
            else:
                map[str] = True
                
        cnt = 0
        for str in arr:
            if map[str]:
                cnt += 1
                if cnt == k:
                    return str
                
        return ""