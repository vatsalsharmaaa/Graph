class Solution {
  public:
  int dp[501][501];
  int rec(int i,int j,string &s1, string &s2)
  {
      if(s1.length()<i){
          return dp[i][j]=s2.length()-j;
      }
      if(s2.length()<j){
          return dp[i][j]=s1.length()-i;
      }
      if(dp[i][j]!=-1) return dp[i][j];
      
      if(s1[i]==s2[j]){
          return dp[i][j]=1+rec(i+1,j+1,s1,s2);
      }
      else{
          int take1=1+rec(i+1,j,s1,s2);
          int take2=1+rec(i,j+1,s1,s2);
          return dp[i][j]=min(take1,take2);
      }
  }
    int minSuperSeq(string &s1, string &s2) {
        // code here
        memset(dp,-1,sizeof(dp));
        int i=0;int j=0;
        int k=rec(i,j,s1,s2);
        return k;
    }
};