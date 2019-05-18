#include<iostream>
#include<vector>
#include<limits.h>

using std::vector;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(0, nums.size(), nums);
    }
    TreeNode* constructMaximumBinaryTree(int l, int r, vector<int>& nums){
        if(l >= r)
            return nullptr;
        int idx = max(l, r, nums);
        TreeNode* node = new TreeNode(nums[idx]);
        node->left = constructMaximumBinaryTree(l, idx, nums);
        node->right = constructMaximumBinaryTree(idx+1, r, nums);

        std::cout << node->val << std::endl;

        return node;
    }
    int max(int l, int r, vector<int>& nums){
        int idx = l;
        for(int i = l; i !=r; i++){
            if(nums[idx] < nums[i]){
                idx = i;
            }
        }
        return idx;
    }
};

int main(){
    vector<int> nums = {3,2,1,6,0,5};
    Solution solution;
    solution.constructMaximumBinaryTree(nums);
    return 0;
}