class Solution(object):
    def minDays(self, bloomDay, m, k):
        """
        :type bloomDay: List[int]
        :type m: int
        :type k: int
        :rtype: int
        """
        # get current bouquet count
        def count(bloomDay, day, k):
            bouquet_count, curr_consec_count = 0, 0
            
            for bDay in bloomDay:
                if bDay <= day:
                    curr_consec_count += 1
                    
                    if curr_consec_count == k:
                        curr_consec_count = 0
                        bouquet_count += 1
                
                else:
                    curr_consec_count = 0
                    
            return bouquet_count
            
        # not possible, at least m * k flowers are required
        if (m * k) > len(bloomDay):
            return -1
        
        # leftmost binary search
        minDays, maxDays = min(bloomDay), max(bloomDay)
        
        while minDays < maxDays:
            mid = (minDays + maxDays) // 2
            
            bouquet_count = count(bloomDay, mid, k)
            
            if bouquet_count < m:
                minDays = mid + 1
            
            else:
                maxDays = mid
        
        return minDays