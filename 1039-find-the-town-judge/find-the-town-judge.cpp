class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> checker(n+1,0);
        for(auto x: trust){
            checker[x[0]]--;
            checker[x[1]]++;

        }

        for(int i=1;i<=n;i++){
            if(checker[i]==n-1)
            return i;
        }

        return -1;
    }
};