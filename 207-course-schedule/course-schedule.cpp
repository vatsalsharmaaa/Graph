class Solution {
public:

    bool toposort(vector<vector<int>>&adj,int n,vector<int>& indegree)
    {   int count =0;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                count++;
            q.push(i);
            }
        }
        while(!q.empty()){
            int temp= q.front();
            q.pop();

            for(auto v: adj[temp]){
                indegree[v]--;
                if(indegree[v]==0){
                    count++;
                    q.push(v);
                }
            }

        }
       return count==n;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int> indegree(numCourses,0);//kahn algo

        for(auto x: prerequisites){
            int a=x[0];
            int b=x[1];
            adj[b].push_back(a);
            //0---->1
            indegree[a]++;
        }

        //if cycle is present toh possible hi nahi hai

        return toposort(adj,numCourses,indegree);
    }
};