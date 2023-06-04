class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1);
        if(n == 0) return {0};
        if(n == 1) return {0,1};
        result[0] = 0;
        result[1] = 1;
        for(int i=2;i<=n;++i){
            result[i] = __builtin_popcount(i);
        }
        return result;
    }
};