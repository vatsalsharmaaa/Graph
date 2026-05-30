class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
          sort(stalls.begin(),stalls.end());
       int start=1;
       int n=stalls.size();
       int end= stalls[n-1]-stalls[0];
       int mid,ans;
       
     
       while(start<=end){
           
           mid= start+(end-start)/2;
           int count=1;
           int pos=stalls[0];
           
           for(int i=1;i<n;i++){
               if(pos+ mid<=stalls[i]){
                   count++;
                   pos=stalls[i];
               }
           }
           if(count<k){
               end=mid-1;
               
           }
           else{
               ans=mid;
               start=mid+1;
           }
       }
       
       return ans;
        
    }
};