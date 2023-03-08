class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1,r = INT_MIN;
        for(int i = 0;i < n; ++i){
            r = max(r,piles[i]);
        }
        while(l < r){
            int mid = (l + r)>>1;
            if(isFinished(piles,h,mid)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
    bool isFinished(vector<int>& piles, int h, int k){
        int cnt = 0;
        for(int i=0;i<piles.size();++i){
            cnt += ceil((double)piles[i]/k);
        }
        return cnt <= h;
    }
};