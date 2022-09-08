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
    void solve(TreeNode* root, vector<int>& ans){
        if(root==NULL){
            return ;
        }
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    
    void morris(TreeNode* root,vector<int>& ans){
        TreeNode* cur=root;
        while(cur){
            if(cur->left == NULL){
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode* prev=cur->left;
                while(prev->right && prev->right != cur){
                    prev=prev->right;
                }
                if(prev->right == NULL){
                    prev->right=cur;
                    cur=cur->left;
                }
                else{
                    prev->right=NULL;
                    ans.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
      //  solve(root,ans);
        morris(root,ans);
        
        return ans;
    }
};