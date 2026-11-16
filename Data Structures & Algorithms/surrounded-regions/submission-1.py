class Solution:
    def solve(self, board: List[List[str]]) -> None:
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        queue = deque([])
        r_len, c_len = len(board), len(board[0])
        visited = set()

        for r in range(r_len):
            if board[r][0] == 'O':
                queue.append((r, 0))
                visited.add((r, 0))
            if board[r][c_len - 1] == 'O':
                queue.append((r, c_len - 1))
                visited.add((r, c_len - 1))

        for c in range(c_len):
            if board[0][c] == 'O':
                queue.append((0, c))
                visited.add((0, c))
            if board[r_len - 1][c] == 'O':
                queue.append((r_len - 1, c))
                visited.add((r_len - 1, c))
    
        while queue:
            r, c = queue.popleft()

            for dr, dc in directions:
                nr, nc = r + dr, c + dc

                if nr < 0 or nr >= r_len or nc < 0 or nc >= c_len or board[nr][nc] == 'X' or (nr, nc) in visited:
                    continue
                
                visited.add((nr, nc))
                queue.append((nr, nc))

        for r in range(r_len):
            for c in range(c_len):
                if board[r][c] == 'O' and (r, c) not in visited:
                    board[r][c] = 'X'