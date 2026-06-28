class Solution {
  public:
  
  vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
  int n,m;
  
  
    void solve(vector<vector<int>>& maze,int i,int j, vector<string>&ans,string curr){
        
           if(i<0||i>n-1||j<0||j>m-1||maze[i][j]==0) return ;
           
        if(i==n-1 && j==m-1){
            ans.push_back(curr);
            return ;
        }
     
        
        for(auto dir:dirs){
            int ni= i+ dir[0];
            int nj= j+ dir[1];
            
            if(ni>=0&&ni<n&&nj>=0&&nj<m&&maze[ni][nj]!=0){
                  if(dir[0]==0&&dir[1]==1){
                curr+='R';
            }
           else if(dir[0]==1&&dir[1]==0){
                curr+='D';
            }
            else if(dir[0]==-1&&dir[1]==0){
                curr+='U';
            }
           else curr+='L';
           
           maze[i][j]=0;
           solve(maze,ni,nj,ans,curr);
           maze[i][j]=1;
           curr.pop_back();
            }
            
          
        }
    }
  
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
        
        n=maze.size();
        m=maze[0].size();
        
        if(maze[0][0]==0){
            return {};
        }
        
        vector<string>ans;
        string curr="";
        solve(maze,0,0,ans,curr);
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};