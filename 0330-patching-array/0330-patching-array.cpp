class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long missing = 1;
        int i = 0, count = 0;
        while(missing <= n){
            if(i < nums.size() && missing >= nums[i]){
                missing += nums[i];
                i++;
            }else{
                count++;
                missing += missing;
            }
        }
        return count;
    }
};