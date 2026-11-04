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
                auto [r_idx, c_idx] = queue.front();
                queue.pop();

                for (int i = 0 ; i < 4 ; ++i) {
                    int dr = r_idx + directions[i][0];
                    int dc = c_idx + directions[i][1];

                    if ((dr >= 0 && dr < r_len) && (dc >= 0 && dc < c_len) \
                    && grid[dr][dc] == 1) {
                        grid[dr][dc] = 2;
                        --fresh;
                        queue.push({dr, dc});
                    }
                }
            }

            ++elapsed_time;
        }

        return (fresh == 0) ? elapsed_time: -1;
    }
};
