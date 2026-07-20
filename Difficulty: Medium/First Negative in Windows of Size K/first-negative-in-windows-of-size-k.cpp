class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int i=0;
        int j=0;
        queue<int>q;
        vector<int>ans;
        while(j<n){
            if(arr[j]<0) q.push(arr[j]);
            
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(q.empty()){
                    ans.push_back(0);
                }
                else{
                     ans.push_back(q.front());
                }
               
                j++;
                if(arr[i]<0)q.pop();
                i++;
            }
        }
        return ans;
    }
};