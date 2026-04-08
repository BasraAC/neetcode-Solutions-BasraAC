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

    int dfs(TreeNode* node, int dep){
        if(!node)return dep; 
        return max(dfs(node->left, dep),dfs(node->right,dep))+1;

    }
public:
    int maxDepth(TreeNode* root) {
        return dfs(root, 0);
    }
};
