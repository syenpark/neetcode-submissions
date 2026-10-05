class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int len = static_cast<int>(edges.size());

        if (len != n - 1) return false;

        vector<vector<int>> adj(n);

        for (const auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        std::unordered_set<int> visited = {0};
        std::vector<int> cstack = {0};

        while (!cstack.empty()) {
            int node = cstack.back();
            cstack.pop_back();

            for (const int neighbor: adj[node]) {
                if (!visited.contains(neighbor)) {
                    visited.insert(neighbor);
                    cstack.push_back(neighbor);
                } 
            } 
        }

        return static_cast<int>(visited.size()) == n;
    }
};
