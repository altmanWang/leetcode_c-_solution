#include<iostream>
#include<vector>
#include<math.h>
using std::vector;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {

        if(nullptr == root)
            return 0;
        vector<int> path;
        return sumRootToLeaf(root, path);
    }
    int sumRootToLeaf(TreeNode * node, vector<int> path){
        if(nullptr == node)
            return 0;
        if(nullptr == node->left && nullptr == node->right){
            int num = 0;
            int cnt = pow(2, path.size());
            for(int i : path){
                num += i * cnt;
                cnt /=2;
            }
            num +=  node->val * cnt;

            return num;
        }
        int res = 0;
        path.push_back(node->val);
        if(nullptr != node->left)
            res += sumRootToLeaf(node->left, path);
        if(nullptr != node->right)
            res += sumRootToLeaf(node->right, path);
        path.pop_back();
        return res;
    }
};

int main(){
    
    TreeNode root(1);

    root.left = new TreeNode(0);
    root.right = new TreeNode(1);

    root.left->left = new TreeNode(0);
    root.left->right = new TreeNode(1);

    root.right->left = new TreeNode(0);
    root.right->right = new TreeNode(1);
    
    Solution solution;
    
    int res = solution.sumRootToLeaf(&root);
    std::cout <<res << std::endl;
    
    return 0;
}