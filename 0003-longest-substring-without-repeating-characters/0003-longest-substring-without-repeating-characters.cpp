class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0,right =0, maxi = INT_MIN;
        unordered_set<char> state;
        while(right < s.size()){
            while(state.count(s[right])==1){
                state.erase(s[left]);
                left++;
            }
            maxi =max(maxi,right-left +1);
            state.insert(s[right]);
            right++;
        }
        return maxi ==INT_MIN ? 0:maxi;
    }
};