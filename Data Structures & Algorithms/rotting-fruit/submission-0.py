from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        queue = deque()
        fresh = 0
        elapsed_time = 0
        r_len, c_len = len(grid), len(grid[0])
        directions = ((-1, 0), (0, -1), (1, 0), (0, 1))

        for r in range(r_len):
            for c in range(c_len):
                if grid[r][c] == 1:
                    fresh += 1
                elif grid[r][c] == 2:
                    queue.append((r, c))

        if fresh == 0:
            return 0

        while queue:
            for _ in range(len(queue)):
                current_r, current_c = queue.popleft()

                for dr, dc in directions:
                    new_r = current_r + dr
                    new_c = current_c + dc

                    if 0 <= new_r < r_len and 0 <= new_c < c_len and grid[new_r][new_c] == 1:
                        fresh -= 1
                        grid[new_r][new_c] = 2
                        queue.append((new_r, new_c))
            
            elapsed_time += 1

        return elapsed_time - 1 if fresh == 0 else -1 