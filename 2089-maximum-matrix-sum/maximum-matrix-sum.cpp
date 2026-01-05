class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int neg=0;
        int n=matrix.size();
        int smallest=INT_MAX;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=abs(matrix[i][j]);

                if(matrix[i][j]<0) neg++;

                smallest= min(smallest,abs(matrix[i][j]));
               
            }
        }
        if(neg%2==0){
            return sum; 
        }
        return sum-(2*smallest);
    }
};