#include<iostream>



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(NULL == root)
            return true;
        return isSymmetricTool(root->left, root->right);
    }
    bool isSymmetricTool(TreeNode* left, TreeNode * right){
        if(NULL == left && NULL == right)
            return true;
        if(NULL == left || NULL == right)
            return false;
        if(left->val == right->val){
            return isSymmetricTool(left->left, right->right) & isSymmetricTool(left->right, right->left);
        }else
            return false;
    }
};