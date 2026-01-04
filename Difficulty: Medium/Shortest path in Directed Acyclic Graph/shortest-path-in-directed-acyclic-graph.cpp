class Solution {
  public:
  
  void topo(int v, vector<int>& indegree,
            vector<vector<int>>& adj,
            vector<int>& topoOrder)
  {
      queue<int> q;
      
      for(int i = 0; i < v; i++){
          if(indegree[i] == 0)
              q.push(i);
      }
      
      while(!q.empty()) {
          int temp = q.front();
          q.pop();
          topoOrder.push_back(temp);
          
          for(auto x : adj[temp]) {
              indegree[x]--;
              if(indegree[x] == 0)
                  q.push(x);
          }
      }
  }
  
  vector<int> shortestPath(int v, int E, vector<vector<int>>& edges) {

      vector<int> indegree(v, 0);
      vector<vector<int>> adj(v);
      vector<vector<int>> weight(v);

      // build graph
      for(auto x : edges){
          adj[x[0]].push_back(x[1]);
          weight[x[0]].push_back(x[2]);
          indegree[x[1]]++;
      }

      vector<int> topoOrder;
      topo(v, indegree, adj, topoOrder);

      vector<int> dist(v, -1);
      dist[0] = 0;

      // relax edges using -1 logic
      for(auto u : topoOrder) {
          if(dist[u] != -1) {
              for(int i = 0; i < adj[u].size(); i++) {
                  int vtx = adj[u][i];
                  if(dist[vtx] == -1 || dist[vtx] > dist[u] + weight[u][i]) {
                      dist[vtx] = dist[u] + weight[u][i];
                  }
              }
          }
      }

      return dist;
  }
};

