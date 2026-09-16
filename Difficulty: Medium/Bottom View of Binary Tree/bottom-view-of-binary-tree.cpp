/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        
        map <int,int>mp;
        if(!root) return {};
        queue<pair<Node *,int>>q;
        q.push({root,0});
        while(!q.empty()){
            Node *temp= q.front().first;
            int lvl=q.front().second;
            
            q.pop();
            if(mp.find(lvl)!=mp.end() || mp.find(lvl)==mp.end()){
                mp.erase(lvl);
                mp[lvl]=temp->data;
            }
            if(temp->left){
                q.push({temp->left,lvl-1});
            }
            if(temp->right){
                q.push({temp->right, lvl+1});
            }
            
        }
        vector<int>res;
        for(auto x: mp){
            int ans=x.second;
            res.push_back(ans);
        }
        return res;
    }
};