class Solution {
public:
    bool check(vector<int> freq){
        for(int i = 0;  i  < 128; i++)if(freq[i] > 1)return true;
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        vector<int> freq(128,0);
        for(int l =0, r=0; r < (int) s.size(); r++){ 
            freq[s[r]]++;
            while(check(freq)){ 
                freq[s[l]]--;
                l++;
            }
            res = max(res, ( r - l ) +1 );
        }
        return res; 
    }
};
