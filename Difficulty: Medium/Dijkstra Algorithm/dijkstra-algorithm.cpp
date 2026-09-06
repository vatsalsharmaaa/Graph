class Solution {
  public:
    typedef pair<int,int> p;

    void solve(int V,
               vector<vector<pair<int,int>>> &adj,
               vector<int> &res,
               int src) {

        priority_queue<p, vector<p>, greater<p>> pq;

        pq.push({0, src});
        res[src] = 0;

        while(!pq.empty()) {

            int weigh = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto vec : adj[node]) {

                int nnode = vec.first;
                int nd = vec.second;

                if(weigh + nd < res[nnode]) {
                    res[nnode] = weigh + nd;
                    pq.push({weigh + nd, nnode});
                }
            }
        }
    }

    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        vector<vector<pair<int,int>>> adj(V);

        for(auto x : edges) {
            int u = x[0];
            int v = x[1];
            int w = x[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> res(V, INT_MAX);

        solve(V, adj, res, src);

        return res;
    }
};