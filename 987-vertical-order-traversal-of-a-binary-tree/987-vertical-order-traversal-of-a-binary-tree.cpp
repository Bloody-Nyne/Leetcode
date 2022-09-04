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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> maps;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            TreeNode* frontNode=node.first;
            int dist=node.second.first;
            int level=node.second.second;
            maps[dist][level].insert(frontNode->val);
            
            if(frontNode->left){
                q.push({frontNode->left,{dist-1,level+1}});
            }
            if(frontNode->right){
                q.push({frontNode->right,{dist+1,level+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto i: maps){
            vector<int> temp;
            for(auto j: i.second){
                temp.insert(temp.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};