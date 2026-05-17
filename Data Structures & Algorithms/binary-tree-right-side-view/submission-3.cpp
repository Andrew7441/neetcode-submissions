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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            TreeNode* rightNode = nullptr;

            for(int i = 0; i < sz; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node){
                    rightNode = node;
                }

                if(rightNode->left) q.push(rightNode->left);
                if(rightNode->right) q.push(rightNode->right);
            }
            if(rightNode){
                res.push_back(rightNode->val);
            }
        }
        return res;
    }
};
