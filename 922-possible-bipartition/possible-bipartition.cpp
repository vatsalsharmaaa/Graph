class Solution {
public:

    bool bfs(vector<vector<int>>&adj,vector<int>&color,int node){
        queue<int>q;

        color[node]=1;
        q.push(node);

        while(!q.empty()){
            int u=q.front();
            q.pop();
           for(auto v: adj[u]){
            if(color[v]==color[u])
            return false;

            if(color[v]==-1){
                color[v]=1-color[u];
                q.push(v);
             }
           }
        }

        return true;
    
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto x: dislikes){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(bfs(adj,color,i)==false){
                    return false;
                }
            }
            
        }
        return true;
    }
};