class Solution(object):
    def numTeams(self, rating):
        """
        :type rating: List[int]
        :rtype: int
        """
        count = self.get_count(rating)
        return self.get_teams(count)
    
    def get_teams(self, count):
        teams = 0
        
        for idx in range(len(count)):
            teams += count[idx][0][0] * count[idx][1][1]
            teams += count[idx][0][1] * count[idx][1][0]
            
        return teams
        
    def get_count(self, rating):
        count = [[[0, 0], [0, 0]] for _ in range(len(rating))]
        
        for idx in range(len(rating)):
            cur, lesser, greater = 0, 0, 0
            num = rating[idx]
            
            while cur < idx:
                if rating[cur] < num:
                    lesser += 1
                else:
                    greater += 1
                    
                cur += 1
                
            count[idx][0][0], count[idx][0][1] = lesser, greater
            lesser, greater = 0, 0
            cur += 1
            
            while cur < len(rating):
                if rating[cur] < num:
                    lesser += 1
                else:
                    greater += 1
                    
                cur += 1
                
            count[idx][1][0], count[idx][1][1] = lesser, greater
            
        return count