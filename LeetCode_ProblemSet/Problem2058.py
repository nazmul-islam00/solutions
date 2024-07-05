# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution(object):
    def nodesBetweenCriticalPoints(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: List[int]
        """
        crc_pt_pos = []
        
        curr_pos = 0
        first, second, third = None, None, head.val
        
        while head.next is not None:
            head = head.next
            first, second, third = second, third, head.val
            
            if ((first and second and third) 
                and (second > first and second > third) 
                or (second < first and second < third)):
                crc_pt_pos += [curr_pos]
                
            curr_pos += 1 
            
        if len(crc_pt_pos) < 2:
            return [-1, -1]
            
        max_distance = crc_pt_pos[-1] - crc_pt_pos[0]
        min_distance = max_distance
        
        for i in range(len(crc_pt_pos) - 1):
            min_distance = min(min_distance, crc_pt_pos[i + 1] - crc_pt_pos[i])
            
        return [min_distance, max_distance]
        
        