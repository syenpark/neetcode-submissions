class Solution {
private:
    int directions[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    void fill_in_stacks (vector<vector<bool>>& pac_visited, vector<pair<int, int>>& pac_stack, vector<vector<bool>>& alt_visited, vector<pair<int, int>>& alt_stack, int r_len, int c_len) {
        for (int r = 0 ; r < r_len ; ++r) {
            pac_visited[r][0] = true;
            pac_stack.push_back({r, 0});

            alt_visited[r][c_len - 1] = true;
            alt_stack.push_back({r, c_len - 1});
        }

        for (int c = 0 ; c < c_len ; ++c) {
            pac_visited[0][c] = true;
            pac_stack.push_back({0, c});

            alt_visited[r_len - 1][c] = true;
            alt_stack.push_back({r_len - 1, c});
        }
    }

    void dfs(vector<vector<bool>>& visited, vector<pair<int, int>>& _stack, vector<vector<int>>& heights) {
        int r_len = static_cast<int>(heights.size());
        int c_len = static_cast<int>(heights[0].size());

        while (!_stack.empty()) {
            auto [r, c] = _stack.back();
            _stack.pop_back();
            
            for (auto [dr, dc]: directions) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= r_len || nr < 0 || nc >= c_len || nc < 0 || visited[nr][nc] == true || heights[nr][nc] < heights [r][c]) {
                    continue;
                }
                _stack.push_back({nr, nc});
                visited[nr][nc] = true;
            }
           
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> common = {};

        int r_len = static_cast<int>(heights.size());
        int c_len = static_cast<int>(heights[0].size());

        vector<vector<bool>> pac_visited (r_len, vector<bool> (c_len, false));
        vector<vector<bool>> alt_visited (r_len, vector<bool> (c_len, false));

        vector<pair<int, int>> pac_stack;
        vector<pair<int, int>> alt_stack;

        fill_in_stacks(pac_visited, pac_stack, alt_visited, alt_stack, r_len, c_len);

        dfs(pac_visited, pac_stack, heights);
        dfs(alt_visited, alt_stack, heights);

        for (int r = 0 ; r < r_len ; ++r) {
            for (int c = 0 ; c < c_len ; ++c) {
                if (pac_visited[r][c] && alt_visited[r][c] == true) {
                    common.push_back({r, c});
                }
            }
        }

        
        return common;
    }
};
