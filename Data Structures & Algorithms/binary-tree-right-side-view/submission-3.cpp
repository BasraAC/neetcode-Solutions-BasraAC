class Solution {
public:
    int vis[101];
    int ans[101];

    void dfs(TreeNode* node, int dep) {
        if (!node) return;
        dfs(node->right, dep + 1);
        if (!vis[dep]) {
            ans[dep] = node->val;
            vis[dep] = true;
        }
        dfs(node->left, dep + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        for (int i = 0; i < 101; i++) vis[i] = 0;   // reset before each run

        dfs(root, 0);
        vector<int> a;
        for (int i = 0; i < 101; i++) {
            if (vis[i]) a.push_back(ans[i]);
        }
        return a;
    }
};