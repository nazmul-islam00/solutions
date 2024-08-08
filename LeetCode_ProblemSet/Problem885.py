class Solution(object):
    def spiralMatrixIII(self, rows, cols, rStart, cStart):
        """
        :type rows: int
        :type cols: int
        :type rStart: int
        :type cStart: int
        :rtype: List[List[int]]
        """
        cell_count = rows * cols
        next_direction = {
            "Right": "Down",
            "Down" : "Left",
            "Left" : "Up",
            "Up"   : "Right"
        }
        cur_direction = "Right"
        cur_radius = 1
        cur_radius_time = 0
        cells_encountered = [[rStart, cStart]]
        row, col = rStart, cStart
        
        while True:
            for _ in range(cur_radius):
                match cur_direction:
                    case "Right": col += 1
                    case "Down" : row += 1
                    case "Left" : col -= 1
                    case "Up"   : row -= 1
                    
                if 0 <= row < rows and 0 <= col < cols:
                    cells_encountered.append([row, col])
                    
                
            if len(cells_encountered) == cell_count:
                break
            
            cur_direction = next_direction[cur_direction]   
            cur_radius_time += 1
            if cur_radius_time == 2:
                cur_radius_time = 0
                cur_radius += 1
                        
        return cells_encountered