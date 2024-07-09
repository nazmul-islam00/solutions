class Solution(object):
    def averageWaitingTime(self, customers):
        """
        :type customers: List[List[int]]
        :rtype: float
        """
        wait, cur = 0, customers[0][0]
        for customer in customers:
            arrival, time = customer[0], customer[1]
            if cur < arrival:
                cur = arrival
            cur += time
            wait += cur - arrival
            
        return float(wait) / len(customers)