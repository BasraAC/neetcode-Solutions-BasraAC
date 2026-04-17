class Solution {
public:
    bool check(vector<int> freq1, vector<int> freq2){ 
        bool flag=true;
        for(int i = 0; i < freq1.size() && flag; i++)if(freq1[i]!=freq2[i])flag=false;
        return flag; 
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())return false;
        vector<int> freq1(26, 0); 
        vector<int> freq2(26, 0); 
        const int k = s1.size();
        for(char a : s1)freq1[a-'a']++;
        for(int i = 0; i < k; i++)freq2[s2[i]-'a']++; 

        bool flag= false; 
        for(int i = 0; i <= s2.size() - k; i++){
            flag|=check(freq1,freq2);
            freq2[s2[i] -'a']--; 
            freq2[s2[i+k] -'a']++; 

        }
        return flag; 
    }
};
