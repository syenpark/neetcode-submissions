class Solution {
private:
    void build_stack(vector<vector<char>>& board, stack<pair<int, int>>& stack_, vector<vector<bool>>& visited) {
        int r_len = static_cast<int>(board.size());
        int c_len = static_cast<int>(board[0].size());

        for (int r = 0 ; r < r_len ; ++r) {
            if (board[r][0] == 'O' && !visited[r][0]) {
                stack_.push({r, 0});
                visited[r][0] = true;
            }

            if (board[r][c_len - 1] == 'O' && !visited[r][c_len - 1]) {
                stack_.push({r, c_len - 1});
                visited[r][c_len - 1] = true;
            }
        }

        for (int c = 0 ; c < c_len ; ++c) {
            if (board[0][c] == 'O' && !visited[0][c]) {
                stack_.push({0, c});
                visited[0][c] = true;
            }

            if (board[r_len - 1][c] == 'O' && !visited[r_len - 1][c]) {
                stack_.push({r_len - 1, c});
                visited[r_len - 1][c] = true;
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int r_len = static_cast<int>(board.size());
        int c_len = static_cast<int>(board[0].size());
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        stack<pair<int, int>> stack_;
        vector<vector<bool>> visited (r_len, vector<bool>(c_len, false));

        build_stack(board, stack_, visited);

        while (!stack_.empty()) {
            auto [r, c] = stack_.top();
            stack_.pop();

            for (auto [dr, dc]: directions) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nr >= r_len || nc < 0 || nc >= c_len || visited[nr][nc] || board[nr][nc] == 'X') {
                    continue;
                }

                stack_.push({nr, nc});
                visited[nr][nc] = true;
            }
        }

        for (int r = 0 ; r < r_len ; ++r) {
            for (int c = 0 ; c < c_len ; ++c) {
                if (board[r][c] == 'O' && !visited[r][c]) {
                    board[r][c] = 'X';
                }
            }
        }
    }
};
