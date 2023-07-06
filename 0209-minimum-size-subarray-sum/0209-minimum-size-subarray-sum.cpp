class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int result = 0;
        int string_length = INT_MAX;
        while(j < nums.size()) {
            result += nums[j];
            while(result >= target){
                string_length = min(string_length, j - i + 1);
                result -= nums[i];
                i++;
            }
            j++;
        }
        if(string_length == INT_MAX) return 0;
        return string_length;
    }
};