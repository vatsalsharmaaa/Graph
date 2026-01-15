typedef pair<int,int> p;

class Solution {
  public:
    vector<int> dijkstra(int v, vector<vector<int>> &edges, int src) {
        
        vector<vector<p>> adj(v);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        vector<int> result(v, INT_MAX);
        priority_queue<p, vector<p>, greater<p>> pq;
        
        result[src] = 0;
        pq.push({0, src});
        
        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for (auto &x : adj[node]) {
                int nw_node = x.first;
                int nw = x.second;
                
                if (wt + nw < result[nw_node]) {
                    result[nw_node] = wt + nw;
                    pq.push({wt + nw, nw_node}); 
                }
            }
        }
        return result;
    }
};

