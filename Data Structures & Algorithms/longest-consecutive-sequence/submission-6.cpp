class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int mx= 1;
        int consec=1;
        if(nums.size()== 0) return 0;
        for(int i = 1; i < (int)nums.size(); i++){
            
            if(nums[i]==nums[i-1]+1)consec++;
            else if(nums[i]==nums[i-1])continue;
            else consec=1;    
            mx=max(mx, consec);
        }
    
        return mx; 
    }
};
