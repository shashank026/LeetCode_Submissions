class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return helper(text1, text2, 0, 0, dp);
    }
    int helper(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
        if(i == s1.size() or j == s2.size()) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(s1[i] == s2[j]){
            ans = 1 + helper(s1, s2, i+1, j+1, dp);
        } else {
            int fs = helper(s1, s2, i+1,j, dp);
            int ss = helper(s1, s2, i,j+1, dp);
            ans = max(fs, ss);
        }
        return dp[i][j] = ans;
    }
};