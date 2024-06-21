class Solution(object):
    def maxSatisfied(self, customers, grumpy, minutes):
        """
        :type customers: List[int]
        :type grumpy: List[int]
        :type minutes: int
        :rtype: int
        """
        if minutes == len(customers):
            return sum(customers)
        
        total = [[0, 0]]
        curr_total_for_all, curr_total_for_ok = 0, 0
        
        for i in range(len(customers)):
            
            curr_total_for_all += customers[i]
            curr_total_for_ok += customers[i] if grumpy[i] == 0 else 0
            
            total.append([curr_total_for_all, curr_total_for_ok])
            
        total.append([curr_total_for_all, curr_total_for_ok])

        print(total)
            
        max_satisfaction = 0
        
        for i in range(1, len(customers) - minutes + 2):
            
            satisfaction = total[i - 1][1] + total[i + minutes - 1][0] - total[i - 1][0] + total[len(customers)][1] - total[i + minutes - 1][1]
            max_satisfaction = max(max_satisfaction, satisfaction)
            print(max_satisfaction)
            
        return max_satisfaction
            
        