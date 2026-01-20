class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // If start or end is blocked
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = true;
        
        int pathLength = 1;
        
        // 8 possible directions
        vector<pair<int,int>> dirs = {
            {1,0},{-1,0},{0,1},{0,-1},
            {1,1},{1,-1},{-1,1},{-1,-1}
        };
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x, y] = q.front();
                q.pop();
                
                // If reached bottom right
                if(x == n-1 && y == n-1) return pathLength;
                
                for(auto &d : dirs){
                    int nx = x + d.first;
                    int ny = y + d.second;
                    
                    if(nx >= 0 && ny >= 0 && nx < n && ny < n &&
                       !visited[nx][ny] && grid[nx][ny] == 0){
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            pathLength++;
        }
        
        return -1;
    }
};
