class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_set<char> charSet(s.begin(),s.end());
        int maxLength = 0;
        for(char ch: charSet){
            int len = 0;
            int i=0, j=0;
            int p = k;
            while(j<n){
                if(s[j] != ch && p>0){
                    p--;
                }else if(s[j] != ch && p == 0){
                    while(s[i] == ch)
                        i++;
                    i++;
                }
                maxLength = max(maxLength, j-i+1);         
                j++;
            }
        }
        return maxLength;
    }
};
