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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool lefttoright = true;
        while(!q.empty()){
            int levelsize = q.size();
            vector<int> level(levelsize);

            for(int i=0; i<levelsize; i++){
                TreeNode* curr = q.front();
                q.pop();

                int index = lefttoright? i : (levelsize-i-1);
                level[index] = curr->val;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(level);
            lefttoright=!lefttoright;
        }
        return ans;
    }
};