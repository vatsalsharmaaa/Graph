
class Solution {
  public:
    vector<int> rightView(Node *root) {
        
        if(!root) return{};
        
        queue<Node *>q;
        q.push(root);
        
        vector<int>res;
        
        while(!q.empty()){
        res.push_back(q.front()->data);
        int size=q.size();
        
        while(size--){
            Node * temp= q.front();
            q.pop();
            if(temp->right)
            q.push(temp->right);
            if(temp->left)
            q.push(temp->left);
        }
       }
        return res;
        
    }
};