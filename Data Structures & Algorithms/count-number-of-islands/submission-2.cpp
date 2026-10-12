class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num_islands = 0;
        const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        const int row_len = static_cast<int>(grid.size());
        const int col_len = static_cast<int>(grid[0].size());

        std::queue<std::pair<int, int>> cqueue;

        for (int r = 0 ; r < row_len ; ++r) {
            for (int c = 0 ; c < col_len; ++c) {
                if (grid[r][c] != '1') continue;

                cqueue.push(std::pair(r, c));
                grid[r][c] = '0';
                ++num_islands;

                while (!cqueue.empty()) {
                    auto [row, col] = cqueue.front();
                    cqueue.pop();

                    for (auto& [dr, dc]: directions) {
                        int new_row = row + dr;
                        int new_col = col + dc;

                        if ((new_row >= 0 && new_row < row_len) && (new_col >= 0 && new_col < col_len) && grid[new_row][new_col] == '1') {
                            grid[new_row][new_col] = '0';
                            cqueue.push(std::pair(new_row, new_col));
                        }
                    }
                }
                
            }
        }


        return num_islands;
    }
};
