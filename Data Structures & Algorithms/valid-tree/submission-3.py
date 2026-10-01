from collections import deque

class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n - 1:
            return False
        elif n == 1 and len(edges) == 0:
            return True 

        adj = {i: [] for i in range(n)}
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        visited = set([edges[0][0]])
        queue = deque([edges[0][0]])

        while queue:
            node = queue.popleft()

            for neighbor in adj[node]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)

        return len(visited) == n

