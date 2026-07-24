class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n,0);
        stack<int> st;
        for(int i =n-1;i>=0;i--){
            while(st.size() >0 && arr[i] >=arr[st.top()]){
                st.pop();
            }
            if(st.empty())
               res[i]=0;
            else res[i]=st.top()-i;
            st.push(i);
        }
        return res;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        return nextLargerElement(temperatures);
    }
};