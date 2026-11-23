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
        int root_u = find_root(parent, u);
        int root_v = find_root(parent, v);

        if (root_u == root_v) return false;
        else {
            parent[root_v] = root_u;
            return true;
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int r_len = static_cast<int>(edges.size());

        vector<int> parent;
        for (int i = 0 ; i <= r_len ; ++i) {
            parent.push_back(i);
        }

        for (int r = 0 ; r < r_len ; ++r) {
            int u = edges[r][0];
            int v = edges[r][1];
            
            if (!newly_union(parent, u, v)) {
                return {u, v};
            }
        }

        return {};
    }
};
