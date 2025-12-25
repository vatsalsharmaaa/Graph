class Solution {
public:

    void BFS(vector<vector<int>>adj,vector<bool>&visited,int i)
    {
        visited[i]=true;
        queue<int>q;
        q.push(i);

        while(!q.empty()){
            int temp= q.front();
            q.pop();
            for(auto v:adj[temp]){
                if(visited[v]==false){
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        vector<bool>visited(n+1,false);

        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
             adj[x[1]].push_back(x[0]);
        }

        BFS(adj ,visited,source);

        if(visited[destination]==false)
        return false;

        return true;
    }
};