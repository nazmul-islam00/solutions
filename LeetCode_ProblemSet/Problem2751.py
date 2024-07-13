class Robot(object):
    def __init__(self, position, direction, health, index):
        self.position = position
        self.direction = direction
        self.health = health
        self.index = index


class Solution(object):
    def survivedRobotsHealths(self, positions, healths, directions):
        """
        :type positions: List[int]
        :type healths: List[int]
        :type directions: str
        :rtype: List[int]
        """
        # initial positions are distinct
        # if all are moving in the same direction, no collision occurs
        if (
            all(direction == "L" for direction in directions) or
            all(direction == "R" for direction in directions)
        ):
            return healths
        
        # sort robots according to positions
        robots = sorted([
            Robot(
                position=positions[i],
                direction=directions[i],
                health=healths[i],
                index=i + 1
            )
            for i in range(len(positions))
        ], key=lambda robot: robot.position)
        
        stack = []
        
        for robot in robots:
            # no collisions possible
            if len(stack) == 0:
                stack.append(robot)
                
            # collision possible 
            # the robot on top of stack must the moving to the right
            # the current robot must be moving to the left
            elif robot.direction == "L" and stack[-1].direction == "R":
                    
                # possible collision
                while len(stack) != 0 and stack[-1].direction == "R":
                    
                    if robot.health > stack[-1].health:
                        stack.pop()
                        robot.health -= 1
                        
                        if robot.health == 0:
                            break
                        
                    elif robot.health < stack[-1].health:
                        stack[-1].health -= 1
                        robot.health = 0
                        
                        if stack[-1].health == 0:
                            stack.pop()
                        
                        break
                    
                    else:
                        stack.pop()
                        robot.health = 0
                        break   
                    
                # if robot survives
                if robot.health > 0:
                    stack.append(robot)
              
            # no collision occurs      
            else:
                stack.append(robot)
                
        return [
            robot.health for robot in
            sorted(stack, key=lambda robot: robot.index)
        ]
                
                    