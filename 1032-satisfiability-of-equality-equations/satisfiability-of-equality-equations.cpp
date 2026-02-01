class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int i){
        if(parent[i]==i){
            return parent[i];
        }
        return parent[i]=find(parent[i]);
    }
    void Union(int x,int y){
      int   parent_x=find(x);
       int parent_y=find(y);

        if(parent_x==parent_y){
            return;
        }
        else if(parent_x!=parent_y){
            if(rank[parent_x]>rank[parent_y]){
            parent[parent_y]=parent_x;
           }
           else{
            if(rank[parent_x]<rank[parent_y])
            parent[parent_x]=parent_y;
           }
        }
        else{
            parent[parent_x]=parent_y;
            rank[parent_y]++;
        }
        

    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26,0);
        rank.resize(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
            rank[i]=i;
        }
       for(auto &x : equations){
            if(x[1] == '='){
                Union(x[0] - 'a', x[3] - 'a');
            }
        }

        
        for(auto &x : equations){
            if(x[1] == '!'){
                if(find(x[0] - 'a') == find(x[3] - 'a')){
                    return false;
                }
            }
        }

        return true;
    }
};