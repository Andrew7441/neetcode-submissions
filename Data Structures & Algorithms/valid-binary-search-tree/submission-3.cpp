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
    void inorder(TreeNode* root, vector<TreeNode*>& nodes){
        if(!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }

    bool isValidBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        inorder(root, nodes);

        for(int i = 0; i < nodes.size() - 1; i++){
            if(nodes[i]->val >= nodes[i+1]->val){
                return false;
            }
        }

        return true;
    }
};
