class Solution {
  public:
    vector<int> twoSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int l=0;
        int h=n-1;
        while(l<h){
            if(arr[l]+arr[h]==target){
                return {l+1,h+1};
            }
            else if(arr[l]+arr[h]<target){
                l++;
            }
            else h--;
        }
        return {-1,-1};
    }
};