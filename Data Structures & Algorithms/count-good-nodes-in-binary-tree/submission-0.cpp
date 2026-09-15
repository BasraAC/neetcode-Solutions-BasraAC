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
    int ans = 0;
    void dfs(TreeNode* node, int mx){ 
        if(!node)return; 
        int curVal = node->val;
        if(mx <= curVal)ans++; 
        dfs(node->right, max(mx, curVal)); 
        dfs(node->left, max(mx,curVal));
    }
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return ans; 
        
    }
};
