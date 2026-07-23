class Solution {
public:
    vector<int> Nge(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n,0);
        stack<int> st;
        for(int i =n-1;i>=0;i--){
            while(st.size() >0 && arr[i] >=st.top()){
                st.pop();
            }
            if(st.empty())
               res[i]=-1;
            else res[i]=st.top();
            st.push(arr[i]);
        }
        return res;
    }
    vector<int> nextGreaterElements(vector<int>& nums) {
       int n = nums.size();
       vector<int> arr;
       for(int i=0;i<n;i++){
         arr.push_back(nums[i]);
       }
       for(int i=0;i<n-1;i++){
         arr.push_back(nums[i]);
       }
       vector<int> res =Nge(arr);
       return vector<int>(res.begin(),res.begin()+n);
    }
};