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
    TreeNode *a1; 
    int best = 0; 
    int dfs(TreeNode *head){ 
        if(!head)return 0; 
        int l = dfs(head->left);
        int r = dfs(head->right); 
        best = max(best, r+l); 
        return max(r,l) + 1; 
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return best; 
        
    }
};
