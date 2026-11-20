class Solution:
    def solve(self, board: List[List[str]]) -> None:
        directions = ((-1, 0), (1, 0), (0, -1), (0, 1))

        r_len, c_len = len(board), len(board[0])
        stack = []
        visited = set()

        for r in range(r_len):
            if board[r][0] == 'O':
                stack.append((r, 0))

            if board[r][c_len - 1] == 'O':
                stack.append((r, c_len - 1))

        for c in range(c_len):
            if board[0][c] == 'O':
                stack.append((0, c))
            if board[r_len - 1][c] == 'O':
                stack.append((r_len - 1, c))

        while stack:
            r, c = stack.pop()
            visited.add((r, c))

            for dr, dc in directions:
                nr = r + dr
                nc = c + dc

                if nr < 0 or nr >= r_len or nc < 0 or nc >= c_len or (nr, nc) in visited:
                    continue

                if board[nr][nc] == 'O':
                    stack.append((nr, nc))
                    visited.add((nr, nc))

        for r in range(r_len):
            for c in range(c_len):
                if (r, c) not in visited and board[r][c] == 'O':
                    board[r][c] = 'X'


