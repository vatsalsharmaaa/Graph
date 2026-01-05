class Solution {
public:
    
    void dfs(vector<vector<int>>& result,vector<vector<int>>&graph,vector<int>&path,int curr){

        path.push_back(curr);

        if(curr==graph.size()-1){
            result.push_back(path);
        }
        for(auto x: graph[curr]){
            dfs(result,graph,path,x);
        }

        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>result;
        vector<int>path;

        dfs(result,graph,path,0);

        return result;
    }
};