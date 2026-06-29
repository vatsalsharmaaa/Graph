class Solution {
public:

    map<int, vector<int>> res;

    void solve(Node* root, int d) {
        if (!root) return;

        res[d].push_back(root->data);
        
        solve(root->left, d + 1);   // next diagonal
        solve(root->right, d);      // same diagonal
        
    }

    vector<int> diagonal(Node *root) {
        if (!root) return {};

        res.clear();

        solve(root, 0);

        vector<int> ans;

        for (auto &x : res) {
            for (int val : x.second)
                ans.push_back(val);
        }

        return ans;
    }
};