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
    bool flag =true; 
    int dfs(TreeNode * node, int dep){
        if(!node)return dep; 
        int ldep = dfs(node->left, dep + 1);
        int rdep = dfs(node->right, dep + 1);
        if(abs(ldep-rdep)>1)flag=false;
        return max(ldep,rdep);
    }
public:
    bool isBalanced(TreeNode* root) {
        dfs(root, 0);
        return flag;
    }
};
