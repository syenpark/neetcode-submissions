class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        def dfs(stack, visited):
            directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]

            while stack:
                r, c = stack.pop()
                visited.add((r, c))

                for dr, dc in directions:
                    nr, nc = r + dr, c + dc

                    if 0 <= nr < r_len and 0 <= nc < c_len and heights[nr][nc] >= heights[r][c] and (nr, nc) not in visited:
                        visited.add((nr, nc))
                        stack.append((nr, nc))

        r_len = len(heights)
        c_len = len(heights[0])

        stack_pac = []
        stack_atl = []

        for r in range(r_len):
            stack_pac.append((r, 0))
            stack_atl.append((r, c_len - 1))

        for c in range(c_len):
            stack_pac.append((0, c))
            stack_atl.append((r_len - 1, c))

        pac = set(stack_pac)
        atl = set(stack_atl)

        dfs(stack_pac, pac)
        dfs(stack_atl, atl)


        return [list(pair) for pair in (pac & atl)]