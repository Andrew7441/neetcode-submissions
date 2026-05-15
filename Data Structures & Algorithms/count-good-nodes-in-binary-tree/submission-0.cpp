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

    void DFS(TreeNode* root, vector<TreeNode*>& v){
        if(!root) return;
        bool c = true;

        for(int i = 0; i < v.size(); i++){
            if(root->val < v[i]->val){
                c = false;
            }
        }
        if(c) ans++;

        v.push_back(root);

        DFS(root->left, v);
        DFS(root->right, v);

        v.pop_back();
    }
    
    int goodNodes(TreeNode* root) {
        vector<TreeNode*> v;
        DFS(root, v);

        return ans;
    }
};
