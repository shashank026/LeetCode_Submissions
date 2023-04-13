class Solution {
public:
//     DP Bottom Up Approach!
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1));
        for(int i=1;i<dp.size();++i){
            for(int j=1;j < dp[0].size();++j){
                int ans = 0;
                if(text1[i - 1] == text2[j - 1]){
                    ans = 1 + dp[i-1][j-1];
                } else {
                    int fs = dp[i-1][j];
                    int ss = dp[i][j-1];
                    ans = max(fs, ss);
                }
                dp[i][j] = ans;
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};