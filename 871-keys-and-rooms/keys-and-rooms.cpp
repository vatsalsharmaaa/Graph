class Solution {
public:

    void bfs(vector<vector<int>>& rooms, vector<bool> &visited,int i){
        queue<int>q;
        visited[i]=true;
        q.push(i);

        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto x: rooms[temp]){
                if(!visited[x]){
                    visited[x]=true;
                    q.push(x);
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n= rooms.size();
        vector<bool> visited(n);
        bfs(rooms,visited,0);

      for (auto v : visited)
{
    if (v == false)
        return false;
}
        return true;
        
    }
};