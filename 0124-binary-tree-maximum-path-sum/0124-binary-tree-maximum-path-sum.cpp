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

    int maxsum(TreeNode* root, int &maxval){
        if(root==NULL) return 0;
        int value = root->val;
        int l=max(0, maxsum(root->left, maxval));
        int r=max(0, maxsum(root->right, maxval));
        maxval = max(maxval, value+l+r);
        return value+max(l,r);
    }

    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=INT_MIN;
        maxsum(root, ans);
        return ans;
    }
};