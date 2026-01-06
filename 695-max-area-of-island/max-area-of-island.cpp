class Solution {
public:

    bool isValid(vector<vector<int>>& grid,int i,int j,int n, int m)
    {
        if(i>=0 && i<n && j>=0 &&j<m && grid [i][j]==1){
            return true;
        }
        return false;
    }
    void dfs(vector<vector<int>>& grid,int &area,int n,int m,int i,int j)
    {
        area++;
        grid[i][j]=0;
        if(isValid(grid,i+1,j,n,m)){
            dfs(grid,area,n,m,i+1,j);
        }
        if(isValid(grid,i-1,j,n,m)){
            dfs(grid,area,n,m,i-1,j);
        }
        if(isValid(grid,i,j+1,n,m)){
            dfs(grid,area,n,m,i,j+1);
        }
        if(isValid(grid,i,j-1,n,m)){
            dfs(grid,area,n,m,i,j-1);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        int sum=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area=0;
                    dfs(grid,area,n,m,i,j);
                    sum =max(sum,area);
                }
            }
        }
        return sum;
    }
};