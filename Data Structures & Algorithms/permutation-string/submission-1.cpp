class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n > m)
            return false;

        unordered_map<char,int> mp;
        for(auto ch: s1)
            mp[ch]++;
        
        int count = 0;
        int i=0, j=0;
        while(j<m){
            if(mp.find(s2[j]) != mp.end()){
                mp[s2[j]]--;
                if(mp[s2[j]] >= 0)
                    count++;
            }
            if(j-i+1 == n){
                if(count == n)
                    return true;
                if(mp.find(s2[i]) != mp.end()){
                    mp[s2[i]]++;
                    if(mp[s2[i]] > 0)
                        count--;
                }
                i++;
            }
            j++;
        }
        return false;
    }
};
