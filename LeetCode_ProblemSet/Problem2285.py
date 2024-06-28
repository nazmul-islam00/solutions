class Solution(object):
    def maximumImportance(self, n, roads):
        """
        :type n: int
        :type roads: List[List[int]]
        :rtype: int
        """
        nodes = {
            idx: {
                "degree": 0,
                "importance": 0
            } for idx in range(n)
        }
            
        for road in roads:
            nodes[road[0]]["degree"] = nodes[road[0]]["degree"] + 1
            nodes[road[1]]["degree"] = nodes[road[1]]["degree"] + 1
            
        keys = sorted(list(nodes.keys()), key=lambda x: nodes[x]["degree"])
        
        for idx in range(n):
            nodes[keys[idx]]["importance"] = idx + 1
            
        return sum(
            [   
                nodes[road[0]]["importance"] + nodes[road[1]]["importance"]
                for road in roads
            ]
        )    