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
    int maxLevelSum(TreeNode* root) { 
        queue<TreeNode*> qu; 
        vector<vector<int>> res; 
        
        if(root == NULL) return 0 ; 
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
        
        int maxi = INT_MIN;      // Move outside to keep the global maximum
        int ansLevel = 1;        // Track the level that has the maximum sum
        int currentLevel = 1;    // Track the active level number during iteration
        
        for(auto i : res){ 
            int sum = 0; 
            for(auto j : i){ 
                sum += j; 
            } 
            
            if(sum > maxi) {     // Strict greater-than check as required by the problem
                maxi = sum; 
                ansLevel = currentLevel; 
            }
            currentLevel++;      // Advance the level counter
        } 
        
        return ansLevel; 
    } 
};
