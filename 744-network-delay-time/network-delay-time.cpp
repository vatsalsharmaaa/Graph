typedef pair<int,int> p;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int >result(n+1,INT_MAX);
        int src=k;
        vector<vector<p>>adj(n+1);
        for(auto &x: times){
            adj[x[0]].push_back({x[1],x[2]});
            
        }

        priority_queue<p,vector<p>, greater<p>>pq;

        result[src]=0;
        pq.push({0,src});

        while(!pq.empty()){
            int wt=pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &e: adj[node])
            {
                int adjNode= e.first;
                int d= e.second;
                if(wt+d<result[adjNode]){
                    result[adjNode]= wt+d;
                    pq.push({wt+d,adjNode});
                }

            }
        }      

        int ans=INT_MIN;

        for(int i=1;i<=n;i++){
            if(result[i]==INT_MAX) return -1;
            ans=max(ans,result[i]);
        }
        return ans;
    }
};