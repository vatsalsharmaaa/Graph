class Solution {
  public:
  
  bool dfs(int node,vector<vector<int>>&adj,vector<int>&color,int curr_color)
  {
      color[node]=curr_color;
      
      for(auto x:adj[node]){
          
          if(color[x]==curr_color){
              return false;
          }
          
          if(color[x]==-1){
              int new_color=1-curr_color;
              if(dfs(x,adj,color,new_color)==false){
                  return false;
              }
          }
          
      }
      return true;
  }
    bool isBipartite(int n, vector<vector<int>> &edges) {
        // Code here
        
        vector<vector<int>>adj(n);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);

        }
        
        vector<int>color(n,-1);
        
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,adj,color,0)==false){
                    return false;
                }
            }
        }
        return true;
        
        
    }
    
};