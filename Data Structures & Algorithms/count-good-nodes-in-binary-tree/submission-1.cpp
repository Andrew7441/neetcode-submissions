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
    int ans = 0;
    vector<int> path;

    void dfs(TreeNode* root){
        if(!root) return;

        bool check = true;
        
        for(int i : path){
            if(i > root->val) check = false;
        }
        if(check) ans++;

        path.push_back(root->val);        
        dfs(root->left);
        dfs(root->right);

        path.pop_back();
    }
    int goodNodes(TreeNode* root) {
        dfs(root);
        return ans;    
    }
};
