class Solution {
public:
    typedef pair<int,int> p;

    vector<int> shortestPath(int V, vector<vector<int>> &edges,
                             int src, int dest) {

        vector<vector<pair<int,int>>> adj(V + 1);

        for(auto x : edges) {
            int u = x[0];
            int v = x[1];
            int w = x[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> dist(V + 1, LLONG_MAX);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        // Dijkstra from destination
        dist[dest] = 0;
        pq.push({0, dest});

        while(!pq.empty()) {

            long long weigh = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(weigh > dist[node])
                continue;

            for(auto a : adj[node]) {

                int new_node = a.first;
                int wt = a.second;

                if(weigh + wt < dist[new_node]) {

                    dist[new_node] = weigh + wt;

                    pq.push({
                        dist[new_node],
                        new_node
                    });
                }
            }
        }

        if(dist[src] == LLONG_MAX)
            return {-1};

        // Sort neighbours by node number
        for(int i = 1; i <= V; i++) {
            sort(adj[i].begin(), adj[i].end());
        }

        vector<int> ans;

        int curr = src;
        ans.push_back(curr);

        while(curr != dest) {

            for(auto a : adj[curr]) {

                int next = a.first;
                int wt = a.second;

                // next must remain on a shortest path
                if(dist[curr] == wt + dist[next]) {

                    curr = next;
                    ans.push_back(curr);
                    break;
                }
            }
        }

        return ans;
    }
};