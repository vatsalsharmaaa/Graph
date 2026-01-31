//Position this line where user code will be pasted.
class Solution {
  public:
  
  void dfs_traverse(int u, vector<vector<int>>&adjrev,vector<bool>&visited)
  {
      visited[u]=true;
      
      for(int &v: adjrev[u]){
          if(!visited[v]){
              dfs_traverse(v,adjrev,visited);
          }
      }
  }
    void dfs(int i,vector<vector<int>> &adj,vector<bool>&visited,stack<int>&st)
    {
        visited[i]=true;
        for(auto x:adj[i]){
            if(visited[x]==false){
                dfs(x,adj,visited,st);
            }
        }
        st.push(i);
    }
    int kosaraju(vector<vector<int>> &adj) {
        
        int v=adj.size();
        
        stack<int>st;
        vector<bool>visited(v,false);
        
        //step1 get order
        for(int i=0;i<v;i++){
            if(visited[i]==false){
                dfs(i,adj,visited,st);
            }
        }
        
        //step2 rev graph
        vector<vector<int>>adjrev(v);
        
        for(int u=0;u<v;u++){
            for(int &x:adj[u]){
                adjrev[x].push_back(u);
            }
        }
        
        //step3 call dfs based on stack
        int countScc=0;
        visited=vector<bool>(v,false);
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!visited[node]){
                dfs_traverse(node,adjrev,visited);
                countScc++;
            }
        }
        
        
        
        return countScc;
        
    }
};