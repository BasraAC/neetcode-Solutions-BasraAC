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
    bool flag=false;
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
    void crawlTree(TreeNode * node, TreeNode * subtree){ 
        if(flag)return; 
        flag|=isSameTree(node, subtree); 
        TreeNode * right = node->right;
        TreeNode * left = node->left;
        if(left) crawlTree(left, subtree); 
        if(right) crawlTree(right, subtree); 


    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        crawlTree(root, subRoot); 
        return flag;

        
        
    }
};
