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

int val = 0; 
void dfs(TreeNode* cur, vector<int> freq){ 
    if(!cur)return; 
    freq[cur->val]++; 
    bool odd = false;
    bool path= true; 
    if(!cur->right && !cur->left){
        for(int i = 1; i < 10; i++){ 
        if(freq[i] % 2 != 0){
            if(odd)path=false;
            else odd= true;
        }
    }
        if(path)val++;

    }

    dfs(cur->right, freq);
    dfs(cur->left, freq);  
    
}
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> freq(10, 0); 
        dfs(root, freq);
        return val; 
        
    }
};
