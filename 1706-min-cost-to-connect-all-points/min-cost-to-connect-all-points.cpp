class Solution {
public:
 typedef pair<int,int> p;

    int prims( vector<vector<p>>&adj,int v){
        priority_queue<p,vector<p>,greater<p>>pq;

        pq.push({0,0});
        vector<bool>inMst(v,false);
        int sum=0;

        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();

            int wt=it.first;
            int node=it.second;

            if(inMst[node]==true) continue;
            
            inMst[node]=true;
            sum+=wt;

            for(auto &temp:adj[node]){
                int neigh=temp.first;
                int nwt=temp.second;

                if(inMst[neigh]==false){
                    pq.push({nwt,neigh});
                }
            }
        }
        return sum;
    }
   
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v=points.size();
        vector<vector<p>>adj(v);
        for(int i=0;i<v;i++){
            for(int j=i+1;j<v;j++){
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];

                int d= abs(x1-x2)+abs(y1-y2);

                adj[i].push_back({j,d});
                adj[j].push_back({i,d});
            }
        }
      return  prims(adj,v);
    }
};