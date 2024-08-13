class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        answer = []
        self.backtrack(sorted(candidates), target, 0, [], answer)
        return answer
    
    def backtrack(self, candidates, target, idx, path, answer):
        if target < 0:
            return
        if target == 0:
            answer.append(path)
            return 
        for i in range(idx, len(candidates)):
            # igonre calls for the same elements
            if i > idx and candidates[i] == candidates[i - 1]:
                continue
            self.backtrack(candidates, target - candidates[i], i + 1, path + [candidates[i]], answer)