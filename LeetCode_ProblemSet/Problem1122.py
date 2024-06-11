class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: List[int]
        """
        count = {}
        extra = []
        
        for num in arr2:
            count[num] = 0
            
        for num in arr1:
            if num in arr2:
                count[num] += 1
            
            else:
                extra.append(num)
                
        extra = sorted(extra)
        ans = []
        
        for num in arr2:
            for _ in range(count[num]):
                ans.append(num)
                
        for num in extra:
            ans.append(num)
            
        return ans