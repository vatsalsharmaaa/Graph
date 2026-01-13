class Solution {
public:

    bool isValid(int i,int k,vector<vector<int>>& grid,int n,int m){
        if(i>=0 && i<n && k>=0 && k<m && grid[i][k]==1){
            return true;
        }
        return false;
    }

    void dfs(int i,int k,vector<vector<int>>& grid,int n,int m){
        grid[i][k]=0;

        if(isValid(i+1,k,grid,n,m)){
            dfs(i+1,k,grid,n,m);
        }
        if(isValid(i-1,k,grid,n,m)){
            dfs(i-1,k,grid,n,m);
        }
        if(isValid(i,k+1,grid,n,m)){
            dfs(i,k+1,grid,n,m);
        }
        if(isValid(i,k-1,grid,n,m)){
            dfs(i,k-1,grid,n,m);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();       // rows
        int m = grid[0].size();    // columns

        // Mark boundary 1s
        for(int i=0; i<n; i++){
            if(grid[i][0] == 1){
                dfs(i, 0, grid, n, m);
            }
            if(grid[i][m-1] == 1){
                dfs(i, m-1, grid, n, m);
            }
        }

        for(int j=0; j<m; j++){
            if(grid[0][j] == 1){
                dfs(0, j, grid, n, m);
            }
            if(grid[n-1][j] == 1){
                dfs(n-1, j, grid, n, m);
            }
        }

        int count = 0;
        for(int i=0; i<n; i++){
            for(int k=0; k<m; k++){
                if(grid[i][k] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};
