class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1, right = 1LL * *max_element(time.begin(), time.end()) * totalTrips;
        while(left < right){
            long long mid = (left + right)/2;
            if(isEnough(time, totalTrips, mid)){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
    bool isEnough(vector<int>& time, int totalTrips, long long given_time){
        long long sum = 0;
        for(int i=0;i<time.size();++i){
            sum += (given_time/ time[i]);
        }
        return sum >= totalTrips;
    }
};