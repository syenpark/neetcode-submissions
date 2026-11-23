class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        parent = list(range(n + 1))

        def find(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]

            return x

        def union(a, b):
            ra, rb = find(a), find(b)

            if ra == rb:
                return False
            parent[rb] = ra

            return True

        for u, v in edges:
            merged = union(u, v)

            if not merged:
                return [u, v]