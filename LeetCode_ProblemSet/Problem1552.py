class Solution(object):
    def maxDistance(self, position, m):
        """
        :type position: List[int]
        :type m: int
        :rtype: int
        """
        position = sorted(position)
        low, high = 0, position[-1] - position[0]
        
        def possible(dist):
            ind, last_ind, count = 1, 0, 1
            
            while ind < len(position) and count < m:
                if position[ind] - position[last_ind] < dist:
                    ind += 1
                else:
                    last_ind = ind
                    ind += 1
                    count += 1
                    
            return count == m
            
        while low < high:
            mid = (low + high + 1) // 2
            
            if not possible(mid):
                high = mid - 1
            else:
                low = mid
                
        return high
    