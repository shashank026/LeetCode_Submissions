class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();++i){
            int rem = target - nums[i];
            auto itr = mp.find(rem);
            if(itr == mp.end()){
                mp.insert({nums[i], i});
            }else{
                return {itr->second, i};
            }
        }
        return { };
    }
};