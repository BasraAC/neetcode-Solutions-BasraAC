class Solution {
public:
    int calctime(vector<int> &piles, int sp){ 
        int time = 0; 
        for(auto ai : piles)time += (ai/sp + (ai%sp>0 ? 1 : 0));
        return time; 
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = *max_element(piles.begin(), piles.end());
        int l = 1, r = mx; 
        int ans = mx;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (calctime(piles, mid) <= h) {
                ans = mid;      // valid → try smaller
                r = mid - 1;
            } else {
                l = mid + 1;    // not valid → need bigger
            }
        }
        return ans; 
    }
};
