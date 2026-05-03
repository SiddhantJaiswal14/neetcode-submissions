class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        int l = 0, r = n-1;
        while(l<r){
            maxArea = max(maxArea, min(heights[l],heights[r]) * (r-l));
            if(heights[l] <= heights[r])
                l++;
            else
                r--;
        }
        return maxArea;
    }
};
