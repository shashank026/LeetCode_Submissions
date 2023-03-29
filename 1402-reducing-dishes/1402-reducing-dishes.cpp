class Solution {
public:
    int maxSatisfaction(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int sufSum = 0;
        int maxAns = 0;
        int i = nums.size() - 1;
        while(i >= 0){
            sufSum += nums[i];
            if(sufSum < 0) break;
            maxAns += sufSum;
            i--;
        }
        return maxAns;
    }
};