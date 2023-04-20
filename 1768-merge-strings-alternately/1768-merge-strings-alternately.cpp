class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i,j;
        i = j = 0;
        string ans;
        while(i < word1.size() and j < word2.size()){
            ans += word1[i];
            ans += word2[j];
            i++;j++;
        }
        if(j < word2.size() and i == word1.size()){
            while(j < word2.size()){
                ans += word2[j];
                j++;
            }
        }
        if(j == word2.size() and i < word1.size()){
            while(i < word1.size()){
                ans += word1[i];
                i++;
            }
        }
        return ans;
    }
};