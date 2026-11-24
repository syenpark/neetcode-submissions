class Solution {
private:
    int find_root(vector<int>& parent, int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    }

    bool newly_union(vector<int>& parent, int u, int v) {
        int ru = find_root(parent, u);
        int rv = find_root(parent, v);

        if (ru == rv) return false;
        else {
            parent[ru] = rv;

            return true;
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        int r_len = static_cast<int>(edges.size());

        vector<int> parent;
        parent.reserve(n);

        for (int i = 0 ; i < n ; ++i) {
            parent.push_back(i);
        }

        for (int r = 0 ; r < r_len ; ++r) {
            if (newly_union(parent, edges[r][0], edges[r][1])) {
                ++count;
            }
        }

        return n - count;
    }
};
