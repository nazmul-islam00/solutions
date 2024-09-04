class Solution(object):
    def robotSim(self, commands, obstacles):
        """
        :type commands: List[int]
        :type obstacles: List[List[int]]
        :rtype: int
        """
        # 0: N, 1: E, 2: S, 3: W 
        direction = 0
        obstacles = set((x, y) for [x, y] in obstacles)
        x, y = 0, 0
        maxDist = 0
        
        for command in commands:
            if command < 0:
                direction = (direction - 1) % 4 if command == -2 else (direction + 1) % 4
                continue
            
            if direction == 0: 
                dx, dy = 0, 1
            elif direction == 1:
                dx, dy = 1, 0
            elif direction == 2:
                dx, dy = 0, -1
            else:
                dx, dy = -1, 0
                
            for i in range(1, command + 1):
                if (x + dx, y + dy) in obstacles:
                    break
                x += dx
                y += dy
             
            dist = int(x ** 2 + y ** 2)   
            maxDist = max(maxDist, dist)

        return maxDist   
           