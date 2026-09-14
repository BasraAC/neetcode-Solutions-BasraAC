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

    TreeNode * res = nullptr;
    void crawlTree(TreeNode* node, int a, int b){ 
        if(!node)return; 
        if(res) return;
        int curVal = node->val; 
        if(curVal > a && curVal > b){if(node->left)crawlTree(node->left, a,b);} 
        else if(curVal < a && curVal < b){if(node->right)crawlTree(node->right, a,b); }
        else {res = node;}
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        crawlTree(root, p->val, q->val); 
        return res;
        
        
    }
};
