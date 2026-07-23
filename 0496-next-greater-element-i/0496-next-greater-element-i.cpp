class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> Nge = nextLargerElement(nums2);
        vector<int> res(nums1.size(),0);
        unordered_map<int,int> map;
        for(int i=0;i<nums2.size();i++)
            map[nums2[i]] =Nge[i];
        for(int i =0;i<nums1.size();i++)
            res[i] = map[nums1[i]];
        return res;
        
    }
};