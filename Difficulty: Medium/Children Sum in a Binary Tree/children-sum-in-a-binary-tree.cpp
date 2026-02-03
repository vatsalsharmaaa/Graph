class Solution {
public:
    bool isSumProperty(Node *root) {
       
        if (root == NULL) return true;

     
        if (root->left == NULL && root->right == NULL) return true;

        int leftSum = 0, rightSum = 0;

        if (root->left)
            leftSum = root->left->data;

        if (root->right)
            rightSum = root->right->data;

        if (root->data != leftSum + rightSum)
            return false;

        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};
