class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = -1;

        int curr = 0;

        for (int i = 0; i < n; i++) {
            curr += nums[i];
            int x = curr % k;

            if (mpp.count(x)) {
                if (i - mpp[x] >= 2)
                    return true;
            } else {
                mpp[x] = i;
            }
        }

        return false;
    }
};