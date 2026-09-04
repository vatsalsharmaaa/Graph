class Solution {
  public:

  int dp[1001][1001];

  int solve(int i, int w, vector<int> &val, vector<int> &wt, int n) {

      if(i >= n) return 0;

      if(dp[i][w] != -1)
          return dp[i][w];

      int take = 0;

      if(wt[i] <= w)
          take = val[i] + solve(i + 1, w - wt[i], val, wt, n);

      int skip = solve(i + 1, w, val, wt, n);

      return dp[i][w] = max(take, skip);
  }

  int knapsack(int W, vector<int> &val, vector<int> &wt) {

      int n = val.size();

      memset(dp, -1, sizeof(dp));

      return solve(0, W, val, wt, n);
  }
};