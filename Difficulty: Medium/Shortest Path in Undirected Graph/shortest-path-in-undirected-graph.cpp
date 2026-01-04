class Solution {
  public:
  
  void bfs(vector<int>&dist,int src,vector<vector<int>> &adj, vector<bool> & visited)
  {
   dist[src]=0;
   
   queue<int>q;
   
   visited[src]=true;
   q.push(src);
   
   while(!q.empty()){
       int temp =q.front();
       q.pop();
       
        for(auto x: adj[temp]){
            if(!visited[x]){
                visited[x]=true;
                dist[x]=dist[temp]+1;
                q.push(x);
            }
        }
   }
  
  }
    vector<int> shortestPath(int v, vector<vector<int>> &edges, int src) {
        vector<int> dist(v,-1);
        vector<vector<int>>adj(v);
        vector<bool> visited(v,false);
        
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            
        }
        
       bfs(dist,src,adj,visited);
        
        return dist;
        
    }
};
