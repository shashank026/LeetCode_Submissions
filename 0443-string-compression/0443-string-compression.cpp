class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i,j;
        i = j = 0;
        int cnt = 0;
        string str;
        while(j < n){
            if(chars[i] == chars[j]){
                cnt++;
                j++;
            }else{
                str += chars[i];
                if(cnt != 1){
                    str += to_string(cnt);
                }
                i = j;
                cnt = 0;
            }
        }
        str += chars[i];
        if(cnt != 1){
            str += to_string(cnt);
        }
        chars.clear();
        for(int i=0;i<str.size();++i){
            chars.push_back(str[i]);
        }
        return chars.size();
    }
};