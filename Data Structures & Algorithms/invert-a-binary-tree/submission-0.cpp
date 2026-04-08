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
    void dfs(TreeNode *node){
        if(!node)return;
        TreeNode *leftNode = node->left; 
        TreeNode *rightNode = node->right; 
        node->left=rightNode;
        node->right=leftNode; 
        dfs(leftNode);
        dfs(rightNode);


    }
public:
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;

        
    }
};
