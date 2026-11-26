from collections import deque

class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        m, n = len(grid), len(grid[0])
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]
        INF = 2147483647

        queue = deque([])

        for r in range(m):
            for c in range(n):
                if grid[r][c] == 0:
                    queue.append((r, c))


        while queue:
            r, c = queue.popleft()

            for dr, dc in directions:
                nr = r + dr
                nc = c + dc

                if nr < 0 or nr >= m or nc < 0 or nc >= n or grid[nr][nc] != INF:
                    continue
                grid[nr][nc] = grid[r][c] + 1
                queue.append((nr, nc))
