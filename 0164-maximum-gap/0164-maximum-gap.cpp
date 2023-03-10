class Solution {
public:
    int maximumGap(vector<int>& nums) {
        map<int, int> mp;
        for(int i=0;i<nums.size();++i){
            mp[nums[i]]++;
        }
        nums.clear();
        for(auto& itr : mp){
            int temp = itr.second;
            while(temp != 0){
                nums.push_back(itr.first);
                temp--;
            }
        }
        int ans = 0;
        for(int i=0;i<nums.size()-1;++i){
            ans = max(ans, abs(nums[i]-nums[i+1]));
        }
        return ans;
    }
};