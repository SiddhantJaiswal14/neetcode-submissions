class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0, r=n-1;
        int leftMax = 0, rightMax = 0;
        int water = 0;
        while(l<r){
            if(height[l] <= height[r]){
                if(leftMax > height[l])
                    water += leftMax - height[l];
                else
                    leftMax = height[l];
                l++;
            }else{
                if(rightMax > height[r])
                    water += rightMax - height[r];
                else
                    rightMax = height[r];
                r--;
            }
        }
        return water;
    }
};
