class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if(n!=m)
            return false;
        vector<int> hash(26,0);
        for(auto ch: s)
            hash[ch-'a']++;
        for(auto ch:t){
            hash[ch-'a']--;
            if(hash[ch-'a'] < 0)
                return false;
        }
        return true;
    }
};
