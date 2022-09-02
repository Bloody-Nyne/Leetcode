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
public:
    int goodNodes(TreeNode* root,int val=INT_MIN) {
        int ans=0;
        if(!root)
            return 0;
        if(root->val>=val)
        {
            val=root->val;
            ans++;
        }
        ans+=goodNodes(root->left,val)+goodNodes(root->right,val);
        return ans; 
    }
};