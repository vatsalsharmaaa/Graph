// class Solution {
//   public:
  
//   bool  isValid(int i,int j,int n,vector<vector<bool>>&visited)
//     {
//         if(i>=0 && i<n && j>=0 && j<n && visited[i][j]==false){
//             return true;
//         }
//         return false;
//     }
//     int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
       
//       vector<vector<bool>>visited(n,vector<bool>(n,false));
       
//       int tx=targetPos[0]-1;
//       int ty=targetPos[1]-1;
       
//       int x1=knightPos[0]-1;
//       int y1=knightPos[1]-1;
       
//       queue<pair<int,int>>q;
//       if(tx==x1 && ty==y1) return 0;
       
//       q.push({x1,y1});
       
//       visited[x1][y1]=true;
       
//       int ans=0;
       
//       while(!q.empty()){
           
//           int size=q.size();
//           ans++;
//           while(size!=0){
//               pair<int,int> p=q.front();
//               q.pop();
               
//               int xx=p.first;
//               int yy=p.second;
               
//               int ax[8]={1,1,-1,-1,2,2,-2,-2};
//               int ay[8]={2,2,-2,-2,1,1,-1,-1};
               
//               for(int i=0;i<8;i++){
//                   int new_x= xx+ ax[i];
//                   int new_y=yy+ay[i];
                   
//                   if(new_x==tx && new_y ==ty){
//                       return ans;
//                   }
                   
//                   if(isValid(new_x,new_y,n,visited)){
//                       visited[new_x][new_y]=true;
//                       q.push({new_x,new_y});
                       
//                   }
//               }
//               size--;
//           }
//       }
      
           
//       return ans;
    
//     }
// };


class Solution {
public:

    bool isValid(int i,int j,int n,vector<vector<bool>>& visited)
    {
        if(i>=0 && i<n && j>=0 && j<n && visited[i][j]==false){
            return true;
        }
        return false;
    }

    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {

        vector<vector<bool>> visited(n,vector<bool>(n,false));

        int tx = targetPos[0]-1;
        int ty = targetPos[1]-1;

        int x1 = knightPos[0]-1;
        int y1 = knightPos[1]-1;

        queue<pair<int,int>> q;
        if(tx==x1 && ty==y1) return 0;

        q.push({x1,y1});
        visited[x1][y1] = true;

        int ans = 0;

        while(!q.empty()){
            int size = q.size();
            ans++;

            while(size != 0){
                pair<int,int> p = q.front();
                q.pop();

                int xx = p.first;
                int yy = p.second;

                int ax[8] = {1,1,-1,-1,2,2,-2,-2};
                int ay[8] = {2,-2,2,-2,1,-1,1,-1};

                for(int i=0;i<8;i++){
                    int new_x = xx + ax[i];
                    int new_y = yy + ay[i];

                    if(new_x==tx && new_y==ty){
                        return ans;
                    }

                    if(isValid(new_x,new_y,n,visited)){
                        visited[new_x][new_y]=true;
                        q.push({new_x,new_y});
                    }
                }

                size--;
            }
        }

        return ans;
    }
};
