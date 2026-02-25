class Solution {
public:
    bool DFS(int u, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[u] = true;

        for (int v : adj[u]) {
            if (!visited[v]) {
                if (DFS(v, u, adj, visited))
                    return true;
            }
            else if (v != parent) {
                return true;  // cycle detected
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
       
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

     
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (DFS(i, -1, adj, visited))
                    return true;
            }
        }
        return false;
    }
};
