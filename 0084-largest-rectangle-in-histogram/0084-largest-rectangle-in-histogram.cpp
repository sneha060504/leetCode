class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();

        // Next Smaller Element on Left
        vector<int> l(n,0);
        stack<int> st1;

        for (int i = 0; i < n; i++) {
            while (st1.size() >0 && h[st1.top()] >= h[i]) {
                st1.pop();
            }
            l[i] = st1.size()==0 ? -1 : st1.top();
            st1.push(i);
        }

        // Next Smaller Element on Right
        vector<int> r(n,0);
        stack<int> st2;

        for (int i = n - 1; i >= 0; i--) {
            while (st2.size() > 0 && h[st2.top()] >= h[i]) {
                st2.pop();
            }
            r[i] = st2.size() ==0 ? n : st2.top();
            st2.push(i);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int width = r[i] - l[i] - 1;
            ans = max(ans, h[i] * width);
        }

        return ans;
    }
};
