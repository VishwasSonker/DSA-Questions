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
    unordered_map<int,int> inorderIndex; // to quickly find root position in inorder
    int preorderIdx = 0;

    TreeNode* build(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;

        // pick current root from preorder
        int rootVal = preorder[preorderIdx++];
        TreeNode* root = new TreeNode(rootVal);

        // split inorder into left & right subtree
        int idx = inorderIndex[rootVal];

        root->left = build(preorder, left, idx - 1);
        root->right = build(preorder, idx + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // store indices of inorder values for O(1) lookup
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        preorderIdx = 0;
        return build(preorder, 0, inorder.size() - 1);
    }
};