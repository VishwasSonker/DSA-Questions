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
    unordered_map<int, int> mp;
    int preidx = 0;

    TreeNode* buildtree(vector<int>& preorder, int left, int right){
        if(left>right){
            return nullptr;
        }
        int rootval = preorder[preidx++];
        TreeNode* root = new TreeNode(rootval);
        int idx = mp[rootval];

        root->left = buildtree(preorder, left, idx-1);
        root->right = buildtree(preorder, idx+1, right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return buildtree(preorder, 0, preorder.size()-1);
    }
};