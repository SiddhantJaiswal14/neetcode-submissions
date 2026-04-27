class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2,0);
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            if(mp.find(target-nums[i]) == mp.end())
                mp[nums[i]] = i;
            else{
                ans[0] = min(i,mp[target-nums[i]]);
                ans[1] = max(i,mp[target-nums[i]]);
            }
        }
        return ans;
    }
};
