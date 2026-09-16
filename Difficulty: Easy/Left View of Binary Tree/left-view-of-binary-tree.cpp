
class Solution {
  public:
    vector<int> leftView(Node *root) {
        if(!root)return {};
        vector<int>res;
        queue<Node *>q;
        q.push(root);
        
        while(!q.empty()){
            
            res.push_back(q.front()->data);
            int size=q.size();
    
            while(size--){
                Node * temp= q.front();
                q.pop();
                
                if(temp->left) q.push(temp->left);
             if(temp->right)q.push(temp->right);
            }
            
        }
        
        return res;
    }
};