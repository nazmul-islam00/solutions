class Solution(object):
    def maxNumEdgesToRemove(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        type1, type2, type3 = [], [], []
        
        for edge in edges:
            if edge[0] == 1:
                type1.append((edge[1] - 1, edge[2] - 1))
            elif edge[0] == 2:
                type2.append((edge[1] - 1, edge[2] - 1))
            else:
                type3.append((edge[1] - 1, edge[2] - 1))
        
        alice = DisjointSet(
            self.init(n), self.init(n)
        )
        bob = DisjointSet(
            self.init(n), self.init(n)
        )
                
        count = (
            self.check(type3, alice, [alice, bob]) + 
            self.check(type1, alice, [alice]) +
            self.check(type2, bob, [bob])
        )
        
        return (
            count if self.check_traversable(alice, n) 
            and self.check_traversable(bob, n) 
            else -1
        )
        
    def init(self, n):
        return [i for i in range(n)]
    
    def check(self, edges, checker, disjoint_sets):
        count = 0
        
        for edge in edges:
            if checker.find_parent(edge[0]) != checker.find_parent(edge[1]):
                for disjoint_set in disjoint_sets:
                    disjoint_set.union(edge[0], edge[1])
                    
            else:
                count += 1
                
        return count
    
    def check_traversable(self, disjoint_set, n):
        return all(
            disjoint_set.find_parent(node) == disjoint_set.find_parent(0)
            for node in range(n)
        )
            
        
class DisjointSet:
    def __init__(self, parent, vertices):
        self.parent = parent
        self.vertices = vertices
        
    def find_parent(self, item):
        if self.parent[item] == item:
            return item
        
        self.parent[item] = self.find_parent(self.parent[item])
        return self.parent[item]
    
    def union(self, item1, item2):
        self.parent[self.find_parent(item1)] = self.find_parent(item2)