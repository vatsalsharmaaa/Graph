class Solution {
  public:
  void dfs(int node,int parent,vector<int> adj[],
           vector<bool>& visited, vector<int>& disc,
           vector<int>& low, vector<bool>& artpoint, int &count)
  {
      int child = 0;
      visited[node] = true;
      disc[node] = low[node] = ++count;   // FIX 1
      
      for(int j = 0; j < adj[node].size(); j++){
          int neigh = adj[node][j];
          
          if(neigh == parent) continue;
          
          if(visited[neigh]){
              low[node] = min(low[node], disc[neigh]);
          }
          else{
              child++;
              dfs(neigh, node, adj, visited, disc, low, artpoint, count);

              if(disc[node] <= low[neigh] && parent != -1){
                  artpoint[node] = true;
              }
              
              low[node] = min(low[node], low[neigh]); // FIX 2
          }
      }
      
      if(child > 1 && parent == -1){
          artpoint[node] = true;
      }
  }

  vector<int> articulationPoints(int v, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> artpoint(v,false), visited(v,false);
        vector<int> disc(v), low(v);
        int count = 0;

        for(int i = 0; i < v; i++){        // FIX 3
            if(!visited[i]){
                dfs(i, -1, adj, visited, disc, low, artpoint, count);
            }
        }

        for(int i = 0; i < v; i++){
            if(artpoint[i]) ans.push_back(i);
        }

        if(ans.empty()) return {-1};
        return ans;
    }
};
