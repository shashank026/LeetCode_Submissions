class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int currMax = INT_MIN;
        for(int i : candies) {
            currMax = max(currMax, i);
        }
        vector<bool> answer;
        for(int i : candies) {
            int candiesWithExtraCandies = i + extraCandies;
            if(candiesWithExtraCandies >= currMax) {
                answer.push_back(true);
            } else {
                answer.push_back(false);
            }
        }
        return answer;
    }
};