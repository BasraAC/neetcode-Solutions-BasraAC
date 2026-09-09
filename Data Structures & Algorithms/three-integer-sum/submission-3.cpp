class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0 ; i < n;i++){ 
            int lptr=i+1;
            int rptr=n-1; 
            while(lptr<rptr){
                if(nums[lptr] + nums[rptr] + nums[i] > 0){
                    rptr--; 
                }
                else if (nums[lptr] + nums[rptr] + nums[i] < 0){
                    lptr++; 
                }
                else{ 
                    ans.push_back({nums[lptr], nums[rptr], nums[i]});
                    lptr++;
                    rptr--;
                }

            }
            
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
