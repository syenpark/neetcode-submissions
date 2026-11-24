class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        r_len = len(edges)
        parent = [i for i in range(n)]
        count = 0

        def find_root(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]

            return x

        def newly_union(u, v):
            ru, rv = find_root(u), find_root(v)

            if ru == rv:
                return False
            
            parent[rv] = ru
        
            return True

        for r in range(r_len):
            u, v = edges[r]

            if newly_union(u, v):
                count += 1

        return n - count


        