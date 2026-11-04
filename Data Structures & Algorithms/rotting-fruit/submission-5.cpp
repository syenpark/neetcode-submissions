class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int r_len = static_cast<int>(grid.size());
        int c_len = static_cast<int>(grid[0].size());
        int elapsed_time = 0;

        std::queue<std::pair<int, int>> queue;

        for (int r_idx = 0 ; r_idx < r_len ; ++r_idx) {
            for (int c_idx = 0 ; c_idx < c_len ; ++c_idx) {
                if (grid[r_idx][c_idx] == 1) ++fresh;
                else if (grid[r_idx][c_idx] == 2) {
                    queue.push({r_idx, c_idx});
                }
            }
        }

        if (fresh == 0) return 0;

        while (!queue.empty() && fresh > 0) {
            int queue_len = static_cast<int>(queue.size());

            for (int i = 0 ; i < queue_len ; ++i) {
                const auto [r_idx, c_idx] = queue.front();
                queue.pop();

                for (const auto& [dr, dc]: directions) {
                    int nr = r_idx + dr;
                    int nc = c_idx + dc;

                    if ((nr >= 0 && nr < r_len) && (nc >= 0 && nc < c_len) \
                    && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        --fresh;
                        queue.push({nr, nc});
                    }
                }
            }

            ++elapsed_time;
        }

        return (fresh == 0) ? elapsed_time: -1;
    }
};
