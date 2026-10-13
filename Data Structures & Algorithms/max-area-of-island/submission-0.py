from collections import deque

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        max_area = 0

        directions = ((0, -1), (0, 1), (-1, 0), (1, 0))

        row_len = len(grid)
        col_len = len(grid[0])

        queue = deque([])

        for r in range(row_len):
            for c in range(col_len):
                if grid[r][c] != 1:
                    continue
                
                grid[r][c] = 2 
                queue.append((r, c))
                current_area = 1

                while queue:
                    cr, cc = queue.popleft()

                    for dr, dc in directions:
                        next_r = cr + dr
                        next_c = cc + dc

                        if 0 <= next_r < row_len and 0 <= next_c < col_len and grid[next_r][next_c] == 1:
                            queue.append((next_r, next_c))
                            grid[next_r][next_c] = 2
                            current_area += 1
                
                max_area = max(max_area, current_area)


        return max_area