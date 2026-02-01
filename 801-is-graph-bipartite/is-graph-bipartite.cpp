class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&color,int curr_color){
        color[node]=curr_color;

        for(auto v:adj[node]){
            if(color[v]==curr_color){
                return false;
            }
            if(color[v]==-1){
               int colorOfV =1-curr_color;

            
            if(dfs(v,adj,color,colorOfV)==false){
                return false;
            }
            }
        
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<vector<int>>adj(n+1);
        for(int i=0;i<n;i++){
            for(int x=0;x<graph[i].size();x++)
            adj[i].push_back(graph[i][x]);
        }

        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
               if( dfs(i,adj,color,1)==false){
                return false;
               }
            }
        }
        return true;
    }
};