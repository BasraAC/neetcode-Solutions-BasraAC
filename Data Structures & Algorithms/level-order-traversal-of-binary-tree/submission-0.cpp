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
    

    void dfs(TreeNode * node, int dep, vector<vector<int>> &ans){ 
        if(!node)return; 
        if (dep == ans.size()) ans.push_back({});  
        ans[dep].push_back(node->val); 
        dfs(node->left, dep+1, ans);dfs(node->right, dep+1, ans);

    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        ans.reserve(2000); 
        dfs(root, 0, ans);
        return ans;
        
    }
};
