#include<iostream>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(nullptr == p && nullptr == q)
            return true;
        if(nullptr == p || nullptr == q)
            return false;
        if(p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        
    }
};