class Solution {
  public:
  
  
  void topo(int i,stack<int>&st,vector<vector<int>>&adj,vector<bool>&vis)
  {
      vis[i]=true;
      
      for(auto x:adj[i]){
          if(!vis[x]){
              topo(x,st,adj,vis);
          }
      }
      st.push(i);
  }
  
  void dfs(int i,vector<vector<int>>&adj,vector<bool>&vis){
      vis[i]=true;
      
      for(auto x:adj[i]){
          if(!vis[x]){
              dfs(x,adj,vis);
          }
      }
  }
  
    int countSCC(int V, vector<vector<int>> &edges) {
        
        vector<bool>visited(V,false);
        vector<vector<int>>adj(V);
        vector<vector<int>>adjrev(V);
        stack<int>st;
        
        
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adjrev[v].push_back(u);
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                topo(i,st,adj,visited);
            }
        }
        int scc=0;
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
        }
        
        while(!st.empty()){
            int i=st.top();
            st.pop();
            if(!visited[i]){
                scc++;
                dfs(i,adjrev,visited);
            }
        }
        return scc;
        
    }
};
















