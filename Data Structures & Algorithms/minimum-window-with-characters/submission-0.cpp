class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> hash(256,0);
        for(auto ch: t)
            hash[ch-'A']++;
        
        string ans = "";
        int startIdx = -1;
        int i=0, j=0;
        int count = 0;
        int len = 1e9;
        while(j<n){
            if(hash[s[j]-'A'] > 0)
                count++;
            hash[s[j]-'A']--;
            while(count == m){
                if(len > j-i+1){
                    startIdx = i;
                    len = j-i+1;
                }
                hash[s[i]-'A']++;
                if(hash[s[i]-'A'] > 0)
                    count--;
                i++;
            }
            j++;
        }
        return startIdx == -1 ? "" : s.substr(startIdx, len);
    }
};
