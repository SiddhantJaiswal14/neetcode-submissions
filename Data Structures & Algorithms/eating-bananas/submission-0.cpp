class Solution {
public:
    bool possibleToEatInMidHrs(int mid, vector<int>& piles, int h){
        int totalHours = 0;
        for(int i=0; i<piles.size(); i++){
            totalHours += ceil((double)piles[i]/(double)mid);
            if(totalHours > h)
                return false;
        }
        return totalHours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(possibleToEatInMidHrs(mid,piles,h)){
                ans = mid;
                high = mid - 1;
            }else
                low = mid + 1;
        }
        return ans;
    }
};
