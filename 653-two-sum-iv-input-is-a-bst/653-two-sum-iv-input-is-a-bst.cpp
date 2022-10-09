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
class BSTIterator {
private: stack<TreeNode*> myStack;
         bool reverse=true;
public:
 
    BSTIterator(TreeNode* root,bool isReverse) {
        reverse=isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* tmpNode=myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
    
    private:
    void pushAll(TreeNode* node){
        for(;node!=NULL;){
            myStack.push(node);
            if(reverse == true)
                node=node->right;
            else
                node=node->left;
        }
    }
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nodes){
        if(!root)
            return;
        
        inorder(root->left,nodes);
        nodes.push_back(root->val);
        inorder(root->right,nodes);
    }
    
    bool solve(TreeNode* root,int k){
        vector<int> nodes;
        inorder(root,nodes);
        int left=0,right=nodes.size()-1;
        while(left<right){
            int sum=nodes[left]+nodes[right];
            if(sum == k)
                return true;
            if(sum < k)
                left++;
            else
                right--;
        }
        return false;
    }
    
    bool findTarget(TreeNode* root, int k) {
        //return solve(root,k);
        if(!root)
            return false;
        
        BSTIterator l(root,false); //next
        BSTIterator r(root,true); //before
        
        int i=l.next();
        int j=r.next();
        
        while(i<j){
            if(i+j == k)
                return true;
            if(i+j < k)
                i=l.next();
            else
                j=r.next();
        }
        return false;
    }
};