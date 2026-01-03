class Solution {
public:
    bool isCycle(int i,vector<vector<int>>& graph,vector<bool> &inrec,vector<bool> &visited)
    {
        visited[i]=true;
        inrec[i]=true;

        for(auto x:graph[i]){
            if(!visited[x]&& isCycle(x,graph,inrec,visited))
            {
                return true;
            }
            else if(visited[x]==true && inrec[x]==true){
                return true;
            }  
        }
        inrec[i]=false;
            return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<bool> inrec(v,false);
        vector<bool> visited(v,false);

        for(int i=0;i<v;i++){
            if(!visited[i]){
                isCycle(i,graph,inrec,visited);
            }
        }

        vector<int>data;
        for(int i=0;i<v;i++){
            if(inrec[i]==false){
                data.push_back(i);
            }
        }

        return data;


    }
};