class Solution:
    computed: dict[str] = {}
    def diffWaysToCompute(self, expression: str) -> list[int]:
        if len(expression) == 0:
            return []
        if len(expression) <= 2:
            return [int(expression)]
        if expression in self.computed:
            return self.computed[expression]
        
        results: list[int] = []
        for i, ch in enumerate(expression):
            if ch.isdigit():
                continue
            leftResults: list[int] = self.diffWaysToCompute(expression[0 : i])
            rightResults: list[int] = self.diffWaysToCompute(expression[i + 1 :])
            
            for leftValue in leftResults:
                for rightValue in rightResults:
                    match ch:
                        case "+": results.append(leftValue + rightValue)
                        case "-": results.append(leftValue - rightValue)
                        case "*": results.append(leftValue * rightValue)
                
        self.computed[expression] = results        
        return results