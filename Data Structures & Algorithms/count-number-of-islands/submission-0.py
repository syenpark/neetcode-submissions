from collections import deque

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        num_islands = 0
        surr = [[-1, 0], [1, 0], [0, -1], [0, 1]]

        col_len = len(grid[0]) # column
        row_len = len(grid) # row

        queue = deque([])
        visited = set()

        for r in range(row_len):
            for c in range(col_len):
                if grid[r][c] == '1':
                    if (r, c) in visited:
                        continue
                    
                    queue.append((r, c))
                    visited.add((r, c))
                    num_islands += 1
                    
                    while queue:
                        current_r, current_c = queue.popleft()

                        for dr, dc in surr:
                            next_r = current_r + dr
                            next_c = current_c + dc

                            if 0 <= next_r < row_len and 0 <= next_c < col_len:
                                if grid[next_r][next_c] == '1':
                                    if (next_r, next_c) not in visited:
                                        queue.append((next_r, next_c))
                                        visited.add((next_r, next_c))
            

        return num_islands