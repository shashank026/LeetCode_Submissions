class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return helper(nums, 0, dp);
    }
    int helper(vector<int>& nums, int i, vector<int>& dp){
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int rob = nums[i] + (helper(nums, i+2, dp));
        int dontrob = helper(nums, i+1,dp);
        return dp[i] = max(rob, dontrob);
    }
};