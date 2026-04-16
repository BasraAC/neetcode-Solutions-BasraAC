class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> mq;
        vector<int> sol;  
        const int n = nums.size();
        for(int i = 0; i < k-1; i++){ 
            while(!mq.empty() && nums[i] > nums[mq.back()])mq.pop_back();
            mq.push_back(i);
        }
        for(int i = k-1; i < n; i++){
            while(!mq.empty() && nums[i] > nums[mq.back()])mq.pop_back();
            mq.push_back(i);
            if(!mq.empty()&& mq.front()==i-k)mq.pop_front();
            sol.push_back(nums[mq.front()]);
        }
        return sol;
    }
};
