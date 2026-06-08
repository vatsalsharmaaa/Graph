class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        int n=a.size();
        int m=b.size();
        int nm=c.size();
        int i=0,j=0,k=0;
        vector<int>ans;
        
        while(i<n&&j<m&&k<nm){
            if(a[i]==b[j] &&b[j]==c[k]){
                if(ans.empty()||ans.back()!=a[i])
                ans.push_back(a[i]);
                i++,j++,k++;
            }
            else {
                int mini= min(a[i],min(b[j],c[k]));
                if(a[i]==mini)i++;
                if(b[j]==mini)j++;
                if(c[k]==mini)k++;
            }
        }
        return ans;
    }
};