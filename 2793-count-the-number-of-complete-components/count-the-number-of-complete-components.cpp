class Solution {
public:
    void BFS(vector<vector<int>>& adj, int i, vector<bool>& visited,int& edge,int& ver) {
        queue<int> q;
        visited[i] = true;
        q.push(i);
       

        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            ver++;
            edge+=adj[temp].size();

            for (auto x : adj[temp]) {
                if (!visited[x]) {
                    visited[x] = true;
                    q.push(x);
                   
                }
            }
        }
       
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // building adjacency list
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int edge=0;
                int ver=0;
                BFS(adj, i, visited,edge,ver);
              
                if(ver*(ver-1)==edge){
                    count++;
                }
            }
        }
        return count;
    }
};
