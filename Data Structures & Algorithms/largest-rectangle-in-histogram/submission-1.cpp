class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size(); 
        vector<int> l (n,-1);
        vector<int> r (n,n);
        stack<int> st_r; 
        stack<int> st_l;
        //scan forward to find first smallest element for each rectangle to the right 
        for(int i = 0; i < n; i++){ 
            while(!st_r.empty()&& heights[i] < heights[st_r.top()]){ 
                r[st_r.top()] = i; 
                st_r.pop();
            }
            st_r.push(i);
        }
        //scan backward to find first smallest element for each rectangle to the left 
        for(int i = n-1; i >= 0; i--){ 
            while(!st_l.empty()&& heights[i] < heights[st_l.top()]){ 
                l[st_l.top()] = i; 
                st_l.pop();
            }
            st_l.push(i);
        }
        int res = 0;
        for(int i = 0; i < n; i++)res = max(res,  heights[i] * (r[i]-l[i] -1));
        return res; 
    }
};