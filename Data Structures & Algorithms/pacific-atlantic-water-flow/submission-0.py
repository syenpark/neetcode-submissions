class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        def dfs(r, c, visited):
            visited.add((r, c))
            directions = [[0, 1], [0, -1], [-1, 0], [1, 0]]
            
            for dr, dc in directions:
                    new_r = r + dr
                    new_c = c + dc

                    if 0 <= new_r < r_len and 0 <= new_c < c_len:
                        if (new_r, new_c) not in visited and heights[new_r][new_c] >= heights[r][c]:
                            dfs(new_r, new_c, visited)

        r_len = len(heights)
        c_len = len(heights[0])

        pac = set()
        atl = set()

        for c in range(c_len):
            dfs(0, c, pac)
            dfs(r_len - 1, c, atl)

        for r in range(r_len):
            dfs(r, 0, pac)
            dfs(r, c_len - 1, atl)

        return [list(pairs) for pairs in (pac & atl)]