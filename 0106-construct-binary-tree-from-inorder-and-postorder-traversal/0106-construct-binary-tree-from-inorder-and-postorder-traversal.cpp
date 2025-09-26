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
    int postidx;

    TreeNode* buildtree(vector<int>& postorder, int left, int right){
        if(left>right){
            return nullptr;
        }
        int rootval = postorder[postidx--];
        TreeNode* root = new TreeNode(rootval);
        int idx = mp[rootval];

        root->right = buildtree(postorder, idx+1, right);
        root->left = buildtree(postorder, left, idx-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        postidx = postorder.size()-1;
        return buildtree(postorder, 0, postorder.size()-1);
    }
};