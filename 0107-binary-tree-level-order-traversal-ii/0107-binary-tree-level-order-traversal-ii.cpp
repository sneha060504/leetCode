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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    queue<TreeNode*> qu;
    vector<vector<int>> res;
    if(root == NULL) return res ;
    qu.push(root);
    while(!qu.empty()){
        vector<int> temp;
        int s = qu.size();
        for(int i =0;i<s;i++){
            TreeNode* curr = qu.front();
                  qu.pop();
            temp.push_back(curr->val);
            if(curr->left != NULL){
            qu.push(curr->left);
            }
             if(curr->right != NULL){
            qu.push(curr->right);
             }
        }
    res.push_back(temp);
    }
    reverse(res.begin(),res.end());  
    return res;

    }
};