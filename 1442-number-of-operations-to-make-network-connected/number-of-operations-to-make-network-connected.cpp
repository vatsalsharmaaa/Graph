class Solution {
public:
vector<int>parent;
vector<int>rank;

    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);

        if(parent_x==parent_y){
            return;
        }
         if(rank[parent_x] > rank[parent_y]){
        parent[parent_y] = parent_x;
    }
    else if(rank[parent_x] < rank[parent_y]){
        parent[parent_x] = parent_y;
    }
    else{
        parent[parent_y] = parent_x;  // or vice versa
        rank[parent_x]++;
    }
}
    int makeConnected(int n, vector<vector<int>>& connections) {

        
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        int component=n;
        for(auto x: connections){
            if(find(x[0])==find(x[1])){
                continue;
            }
            else{
                Union(x[0],x[1]);
                component--;
            }
        }
        if(connections.size()<n-1) return -1;
        return component-1;
    }
};