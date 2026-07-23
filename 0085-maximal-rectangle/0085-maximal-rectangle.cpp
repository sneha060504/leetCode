class Solution {
public:
    vector<int> nextSmallerLeft(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i = 0; i <= n -1; i++){
            while(st.size() > 0 && arr[i]<= arr[st.top()]){
                    st.pop();
            }
            ans[i]=st.size() == 0? -1: st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nextSmallerRight(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(st.size() > 0 && arr[i]<= arr[st.top()]){
                    st.pop();
            }
            ans[i]=st.size() == 0? n: st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = INT_MIN;
        int n  = heights.size();
        vector<int> l = nextSmallerLeft(heights);
        vector<int> r = nextSmallerRight(heights);
        for(int i = 0; i< n; i++){
            int area = (r[i] - l[i] -1)* heights[i];
            maxArea = max(area,maxArea);
        }
        return maxArea;
    }
    vector<vector<int>> convert(vector<vector<char>>& matrix){
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> ans(r, vector<int>(c));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ans[i][j] = matrix[i][j] - '0';
            }
    }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> m = convert(matrix);
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> newArr(c,0);
        int maxArea = 0;
        for(int i = 0; i < r;i++){
            for(int j = 0; j < c;j++){
                newArr[j] = m[i][j] == 0? 0: newArr[j]+1;
            }
            maxArea = max(maxArea,largestRectangleArea(newArr));
        }
        return maxArea;
    }
};