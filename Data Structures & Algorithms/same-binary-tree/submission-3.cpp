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
    int dfs(TreeNode* a, TreeNode *b){ 
        if(!a && !b)return true; 
        if(!a || !b)return false;
        //check if current nodes are the same 
        if(a->val != b->val)return false;
        //dfs into left and right sub children of both trees 
        return dfs(a->right, b->right) && dfs(a->left, b->left); 
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        return dfs(p,q);
        
    }
};
