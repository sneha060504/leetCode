class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> left(n, -1); 
        vector<int> right(n, n); 
        
        stack<int> leftStack; 
        stack<int> rightStack; 
        
        // Calculate next lower element from the left.
        for (int i = n - 1; i >= 0; i--) {
            while (!leftStack.empty() && nums[leftStack.top()] > nums[i]) {
                left[leftStack.top()] = i;
                leftStack.pop();
            }
            leftStack.push(i);
        }
        
        // Calculate next lower element from the right
        for (int i = 0; i < n; i++) {
            while (!rightStack.empty() && nums[rightStack.top()] > nums[i]) {
                right[rightStack.top()] = i; 
                rightStack.pop();
            }
            rightStack.push(i);
        }
        
        int maxScore = 0; 
        
        // Calculate the maximum score for good subarrays
        for (int i = 0; i < n; i++) {
            if (left[i] < k && right[i] > k) {
                int subarrayScore = nums[i] * (right[i] - left[i] - 1);
                maxScore = max(maxScore, subarrayScore); 
            }
        }
        
        return maxScore;
    }
};