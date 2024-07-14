class Solution(object):
    def countOfAtoms(self, formula):
        """
        :type formula: str
        :rtype: str
        """
        elements = self.helper(formula)
        return "".join([
            key + (str(elements[key]) if elements[key] > 1 else "")
            for key in sorted(elements.keys())
        ])
    
    
    def helper(self, formula):
        """Parses the formula & returns dict consisting counts."""
        idx, stack = 0, []
        
        while idx < len(formula):
            
            element, count = formula[idx], 0
            
            while idx + 1 < len(formula) and 'a' <= formula[idx + 1] <= 'z':
                element += formula[idx + 1].__str__()
                idx += 1
                
            while idx + 1 < len(formula) and '0' <= formula[idx + 1] <= '9':
                count = count * 10 + int(formula[idx + 1])
                idx += 1
            
            stack.append((element, count or 1))
                
            idx += 1
            
        # process multipliers
        idx = 0
        while idx < len(stack):

            if stack[idx][0] == ')':
                count = stack[idx][1]
                
                iidx = idx - 1
                while stack[iidx][0] != '(':
                    t = list(stack[iidx])
                    t[1] *= count
                    stack[iidx] = tuple(t)
                    iidx -= 1
                    
                t = list(stack[iidx])
                t[0] = '{'
                stack[iidx] = tuple(t)
                
            idx += 1
            
        return self.get_dict(stack)
        
        
    def update(self, dict1, dict2):
        """Merges two dicts."""
        result = dict1
        
        for key in dict2.keys():
            
            if key in dict1:
                result[key] = result[key] + dict2[key]
                
            else:
                result[key] = dict2[key]
                
        return result
    
    
    def get_dict(self, stack):
        """Returns dictionary containing keys and counts."""
        dict = {}
        
        for tuple in stack:
            if tuple[0] in ('(', ')', '{'):
                continue
            
            if tuple[0] in dict:
                dict[tuple[0]] = dict[tuple[0]] + tuple[1]
                
            else:
                dict[tuple[0]] = tuple[1]
                
        return dict
                    
                    
solution = Solution()
print(solution.countOfAtoms("H2O"))                   