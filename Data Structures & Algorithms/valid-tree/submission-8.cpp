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

        std::vector<bool> visited(n, false);
        visited[0] = true;
        std::queue<int> cqueue;
        cqueue.push(0);
        int count = 1;

        while (!cqueue.empty()) {
            int node = cqueue.front();
            cqueue.pop();

            for (const int neighbor: adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    ++count;
                    cqueue.push(neighbor);
                } 
            } 
        }

        return count == n;
    }
};
