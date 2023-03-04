class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        int minI, maxI, lowerI;
        minI = maxI = lowerI = -1;
        
        for(int i=0;i<n;++i){
            if(nums[i] < minK or nums[i] > maxK){
                lowerI = i;
            }
            if(nums[i] == minK) minI = i;
            if(nums[i] == maxK) maxI = i;
            ans += max(0, min(maxI, minI) - lowerI);
        }
        return ans;
    }
};