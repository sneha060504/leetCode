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
    vector<TreeNode* > arr;
    void inorder(TreeNode* root){
        if(root == NULL) return ;
        inorder(root->left);
        arr.push_back(root);
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        TreeNode* temp = new TreeNode(-1);
        TreeNode* res = temp;
        for(auto node : arr){
            node->left = NULL;
            temp->right = node;
            temp = temp->right;
        }
        return res->right;
    }
};