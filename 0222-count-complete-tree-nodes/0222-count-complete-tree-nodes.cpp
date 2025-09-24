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
    int countNodes(TreeNode* root) {
        int ans=0;
        if(!root) return ans;
        queue<TreeNode*> q;
        vector<vector<int>> arr;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            arr.push_back(temp);
        }
        int len = arr.size();
        for(int i=0; i<len-1; i++){
            ans+=pow(2, i);
        }
        ans+=arr[len-1].size();
        return ans;
    }
};