class Solution {
public:
    int maxSubArray(vector<int>& nums) {
            int n=nums.size();
            vector<int> dp(nums);
            for(int i=1; i<n; i++){
                dp[i]=max(nums[i], dp[i-1]+nums[i]);
            }
            int mx=-1000000000;
            for(int i=0; i<n; i++){
                mx=max(dp[i], mx);
            }
            return mx;
    }
};
