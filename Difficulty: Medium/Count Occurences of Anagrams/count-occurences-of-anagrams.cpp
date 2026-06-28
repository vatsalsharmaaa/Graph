class Solution {
  public:
  
  bool allzero(vector<int>&freq){
      
      for(auto i: freq){
          if(i!=0) return false;
      }
      return true;
  }
    int search(string &pat, string &txt) {
        // code here
        int n=txt.length();
        
        
        vector<int>freq(26,0);
        
        for(int i=0;i<pat.length();i++){
            int ch=pat[i];
            
            freq[ch-'a']++;
            
        }
       
        int i=0;
        int j=0;
        int k=pat.size();
        int count=0;
        
        while(j<n){
            
            freq [ txt[j] - 'a' ]--;
            if(j-i+1==k){ 
                if(allzero(freq)) count++;
                
                freq[txt[i]-'a']++;
                i++;
            }
            j++;
            
        }
        return count;
    }
};