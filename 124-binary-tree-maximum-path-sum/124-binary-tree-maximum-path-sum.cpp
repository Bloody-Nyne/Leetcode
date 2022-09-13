/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int solve(TreeNode* root,int& maxSum){
        if(!root) return 0;
        
        int left = solve(root->left,maxSum);
        if(left < 0) left = 0;
        int right = solve(root->right,maxSum);
        if(right < 0) right = 0;
        
        int sum = root->val + left + right;
        
        maxSum = max(maxSum,sum);
        return root->val + max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        solve(root,maxSum);
        return maxSum;
    }
};