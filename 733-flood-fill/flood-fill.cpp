class Solution {
public:
    bool isValid(vector<vector<int>>& image,int i,int j,int n,int m,int same)
    {
        if(i>=0 && i<n && j>=0 && j<m && image[i][j]==same)
        return true;

        return false;
    }
    void DFS(int i,int j,vector<vector<int>>& image,int color,int n,int m,int same)
    {
        image[i][j]=color;

        if(isValid(image,i+1,j,n,m,same)){
            DFS(i+1,j,image,color,n,m,same);
        }
         if(isValid(image,i-1,j,n,m,same)){
            DFS(i-1,j,image,color,n,m,same);
        }
         if(isValid(image,i,j+1,n,m,same)){
            DFS(i,j+1,image,color,n,m,same);
        }
         if(isValid(image,i,j-1,n,m,same)){
            DFS(i,j-1,image,color,n,m,same);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int same= image[sr][sc];

       if (same == color) return image;
       
        DFS(sr,sc,image,color,n,m,same);
        return image;
    }
};