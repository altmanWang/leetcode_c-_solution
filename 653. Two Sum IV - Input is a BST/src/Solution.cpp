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
    bool findTarget(TreeNode* root, int k) {
        if(nullptr == root)
            return false;
        vector<int> nums;
        findTarget(root, nums);
        int l = 0;
        int r = nums.size() - 1;
        int sum = 0;
        while(l < r){
            sum = nums[l] + nums[r];
            if(sum == k)
                return true;
            else if(sum < k)
                l +=1;
            else 
                r -=1;
        }
        return false;
    }
    void findTarget(TreeNode * node, vector<int> & nums){
        if(nullptr == node)
            return;
        findTarget(node->left, nums);
        nums.push_back(node->val);
        findTarget(node->right, nums);
    }

};