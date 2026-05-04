class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> st;
        int i=0, j=0;
        int longest = 0;
        while(j<n){
            if(st.find(s[j]) == st.end()){
                st.insert(s[j]);    
                longest = max(longest,j-i+1);
                j++;
            }else{
                while(!st.empty() && st.find(s[j]) != st.end()){
                    st.erase(s[i]);
                    i++;
                }
            }
        }
        return longest;
    }
};
