class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        vector<vector<int>>adj(V);
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>dist(V,-1);
        vector<bool>visited(V,false);
        
        queue<int>q;
        q.push(src);
        dist[src]=0;
        visited[src]=true;
        
        while(!q.empty()){
            int node= q.front();
            
            q.pop();
            
            for(auto x: adj[node]){
                if(!visited[x]){
                    visited[x]=true;
                    dist[x]=dist[node]+1;
                    q.push(x);
                }
            }
        }
        return dist[dest]==-1?-1:dist[dest];
    }
};
