class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        parent = list(range(n + 1))

        def find_root(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]

            return x

        def newly_union(a, b):
            ra, rb = find_root(a), find_root(b)

            if ra == rb:
                return False

            parent[rb] = ra

            return True

        for u, v in edges:
            if not newly_union(u, v):
                return [u, v]