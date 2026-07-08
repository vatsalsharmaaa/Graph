class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int n=arr.size();
        int i=0;
        int j=0;
        int ans=0;
        int platforms=0;
        
        while(i<n && j<n){
            
            if(arr[i]<=dep[j]){
                platforms++;
                ans=max(ans,platforms);
                i++;
                
            }
            
            else {
                platforms--;
                j++;
            }
        }
        return ans;
    }
};
