/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res;
        tree2vector(root, k, res);
        return res;
    }
    void tree2vector(TreeNode * node, int & k, int & res){
        if(node == nullptr)
            return;
        tree2vector(node->left, k, res);
        k -=1;
        if(k == 0){
            res = node->val;
            return;
        }
        tree2vector(node->right, k, res);
    }
};