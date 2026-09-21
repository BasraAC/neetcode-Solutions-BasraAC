class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 1e9; 
        vector<int> dp (amount + 1, INF);
        dp[0]=0; 
        for(int i = 0; i < amount+1; i++){
            for(auto c : coins) {
                if(i-c < 0)continue;
                dp[i]=min(dp[i], dp[i-c] + 1); 
            }
        } 
        return dp[amount] != INF ? dp[amount] : -1; 

        
    }
};
