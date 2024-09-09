# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
        
class Solution(object):
    def spiralMatrix(self, m, n, head):
        """
        :type m: int
        :type n: int
        :type head: Optional[ListNode]
        :rtype: List[List[int]]
        """
        matrix = [[-1 for _ in range(n)] for _ in range(m)]
        direction = "right"
        x, y = 0, 0
        while True:
            matrix[x][y] = head.val
            head = head.next
            if head is None:
                break
            if direction == "right":
                if y + 1 < n and matrix[x][y + 1] == -1:
                    y += 1
                    continue
                direction = "down"
                x += 1
            elif direction == "down":
                if x + 1 < m and matrix[x + 1][y] == -1:
                    x += 1
                    continue
                direction = "left"
                y -= 1
            elif direction == "left":
                if y > 0 and matrix[x][y - 1] == -1:
                    y -= 1
                    continue
                direction = "up"
                x -= 1
            else:
                if x > 0 and matrix[x - 1][y] == -1:
                    x-= 1
                    continue
                direction = "right"
                y += 1
        return matrix