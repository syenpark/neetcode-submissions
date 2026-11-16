class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r_len = static_cast<int>(board.size());
        int c_len = static_cast<int>(board[0].size());
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        vector<vector<bool>> visited (r_len, vector<bool>(c_len, false));
        deque<pair<int, int>> dqueue;

        for (int r = 0 ; r < r_len ; ++r) {
            if (board[r][0] == 'O') {
                visited[r][0] = true;
                dqueue.push_back({r, 0});
            }
            if (board[r][c_len - 1] == 'O') {
                visited[r][c_len - 1] = true;
                dqueue.push_back({r, c_len - 1});
            }
        }

        for (int c = 0 ; c < c_len ; ++c) {
            if (board[0][c] == 'O') {
                visited[0][c] = true;
                dqueue.push_back({0, c});
            }
            if (board[r_len - 1][c] == 'O') {
                visited[r_len - 1][c] = true;
                dqueue.push_back({r_len - 1, c});
            }
        }

        while (!dqueue.empty()) {
            auto [r, c] = dqueue.front();
            dqueue.pop_front();
            visited[r][c] = true;

            for (auto [dr, dc]: directions) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nr >= r_len || nc < 0 || nc >= c_len || board[nr][nc] == 'X' || visited[nr][nc] == true) {
                    continue;
                }

                visited[nr][nc] = true;
                dqueue.push_back({nr, nc});
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
