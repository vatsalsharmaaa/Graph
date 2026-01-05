class Solution {
  public:
    typedef pair<int,int> p;

    int spanningTree(int V, vector<vector<int>>& edges) {

        priority_queue<p, vector<p>, greater<p>> pq;
        // {wt, node}

        vector<vector<p>> adj(V);   // size + store pair

        for (auto x : edges) {
            adj[x[0]].push_back({x[1], x[2]});  //  store wt
            adj[x[1]].push_back({x[0], x[2]});
        }

        pq.push({0, 0});
        vector<bool> inMst(V, false);

        int sum = 0;

        while (!pq.empty()) {
            auto it = pq.top();   
            pq.pop();

            int wt = it.first;
            int node = it.second;

            if (inMst[node] == true)
                continue;

            inMst[node] = true;
            sum += wt;

            for (auto &temp : adj[node]) {

                int neighbour = temp.first;    
                int neigh_wt = temp.second;

                if (inMst[neighbour] == false) {
                    pq.push({neigh_wt, neighbour}); 
                }
            }
        }
        return sum;
    }
};
