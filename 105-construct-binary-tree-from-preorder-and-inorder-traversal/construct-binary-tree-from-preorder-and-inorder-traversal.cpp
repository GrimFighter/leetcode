/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 *right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
        {
            unordered_map<int, int> map;

            for (int i = 0; i < inorder.size(); ++i)
            {
                map[inorder[i]] = i;
            }
            return build(preorder, 0, preorder.size() - 1, inorder, 0,
                inorder.size() - 1, map);
        }

    TreeNode* build(vector<int> &preorder, int preStart, int preEnd,
        vector<int> &inorder, int inStart, int inEnd,
        unordered_map<int, int> &map)
    {
        if (preStart > preEnd)
            return nullptr;

        int rootValue = preorder[preStart];
        int rootIndex = map.at(rootValue);
        int leftSize = rootIndex - inStart;

        TreeNode *root = new TreeNode(rootValue);

        root->left = build(preorder, preStart + 1, preStart + leftSize,
            inorder, inStart, rootIndex - 1, map);
        root->right = build(preorder, preStart + leftSize + 1, preEnd,
            inorder, rootIndex + 1, inEnd, map);

        return root;
    }
};