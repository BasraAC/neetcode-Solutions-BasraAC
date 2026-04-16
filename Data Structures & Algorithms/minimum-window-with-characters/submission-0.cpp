class Solution {
public:
    bool check(const vector<int>& base, const vector<int>& cur) { 
        for (int i = 0; i < 128; i++) {
            if (cur[i] < base[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        vector<int> freqt(128, 0); 
        vector<int> freqCur(128, 0); 
        int lMax = -1, rMax = -1; 

        for (char c : t) freqt[c]++; 

        for (int l = 0, r = 0; r < (int)s.size(); r++) { 
            freqCur[s[r]]++;

            while (check(freqt, freqCur)) { 
                if (lMax == -1 || (r - l) < (rMax - lMax)) {
                    rMax = r;
                    lMax = l;
                }
                freqCur[s[l]]--;
                l++;
            }
        }

        if (lMax == -1) return "";
        return s.substr(lMax, rMax - lMax + 1);
    }
};