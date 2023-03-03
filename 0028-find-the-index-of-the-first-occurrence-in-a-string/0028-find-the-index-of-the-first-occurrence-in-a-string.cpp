class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() <= haystack.size()){
            for(int i=0;i<haystack.size();++i){
                if(haystack.substr(i, needle.size()) == needle) return i;
            }
            return -1;
        }
        return -1;
    }
};