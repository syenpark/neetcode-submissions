class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        adj_matrix = [[] for _ in range(n + 1)]
        
        def connected(start, target):
            visited = set()
            stack = [start]
            visited.add(start)
                
            while stack:
                current_node = stack.pop()

                for neighbor in adj_matrix[current_node]:
                    if neighbor not in visited:
                        stack.append(neighbor)
                        visited.add(neighbor)
                    if neighbor == target:
                        return True

            return False

        for u, v in edges:
            if connected(u, v):
                return [u, v]
            
            adj_matrix[u].append(v)
            adj_matrix[v].append(u)