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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        int count = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            count++;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                
                if(count != depth -1){
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
                else{
                    TreeNode* newNode1 = new TreeNode(val);
                    newNode1->left = node->left;
                    node->left = newNode1;
                    
                    TreeNode* newNode2 = new TreeNode(val);
                    newNode2->right = node->right;
                    node->right = newNode2;
                }
            }
        }
        return root;
    }
    
};