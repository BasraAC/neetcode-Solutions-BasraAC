class Solution {
public:
    int maxArea(vector<int>& heights) {
        //maximize the expression min(heights[l], heights[r]) * (r-l);
        int mx = -1e9; 
        int n = heights.size();
        for(int l = 0, r = n -1; l < r;){
            mx = max(mx, min(heights[l],heights[r]) * (r-l));
            if(heights[l] < heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return mx; 
        
        
    }
};
