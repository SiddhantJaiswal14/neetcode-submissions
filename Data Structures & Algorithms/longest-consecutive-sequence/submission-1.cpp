class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int longest = 0;
        for(auto it: s){
            if(s.find(it-1) == s.end()){ // it can be a start of a sequence
                int length = 1;
                while(s.find(it + length) != s.end())// increase the length as far as we can find consecutives
                    length++;
                
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
