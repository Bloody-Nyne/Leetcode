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
    void solve(TreeNode* root,TreeNode* copy,TreeNode* target,TreeNode*& ans){
        if(!root)
            return;
        if(root == target){
            ans=copy;
        }
        solve(root->left,copy->left,target,ans);
        solve(root->right,copy->right,target,ans);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans=NULL;
        solve(original,cloned,target,ans);
        return ans;
    }
};