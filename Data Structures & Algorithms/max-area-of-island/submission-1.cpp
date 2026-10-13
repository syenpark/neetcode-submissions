class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int row_len = static_cast<int>(grid.size());
        int col_len = static_cast<int>(grid[0].size());
        const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        std::queue<std::pair<int, int>> cqueue;

        for (int r = 0 ; r < row_len ; ++r) {
            for (int c = 0 ; c < col_len ; ++c) {
                if (grid[r][c] != 1) continue;

                grid[r][c] = 2;
                cqueue.push(std::pair(r, c));
                int current_area = 1;

                while (!cqueue.empty()) {
                    auto [cr, cc] = cqueue.front();
                    cqueue.pop();

                    for (auto& [dr, dc]: directions) {
                        int next_r = cr + dr;
                        int next_c = cc + dc;

                        if (next_r < 0 || next_r >= row_len || next_c < 0 || next_c >= col_len || grid[next_r][next_c] != 1) {
                            continue;
                        }

                        cqueue.push(std::pair(next_r, next_c));
                        grid[next_r][next_c] = 2;
                        ++current_area;
                    }
                }

                max_area = std::max(max_area, current_area);
            }
        }

        return max_area;
    }
};
