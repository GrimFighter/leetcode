/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    private:
        void dfs(TreeNode *root, int path, int &ans)
        {   
            if(root == nullptr) return;
            if (root->left == nullptr && root->right == nullptr)
            {
                ans += 10 *path + root->val;
                return;
            }

            dfs(root->left, 10 *path + root->val, ans);
            dfs(root->right, 10 *path + root->val, ans);
        }

    public:
        int sumNumbers(TreeNode *root)
        {   int ans = 0;
            if (root == nullptr) return ans;
            
            dfs(root, 0, ans);

            return ans;
        }
};