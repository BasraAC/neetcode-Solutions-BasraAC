class Solution {
public:
    bool isValid(string t) {
        stack<int> s; 
        bool res = true;
        if(t.size()%2!=0)res=false;
        for(auto c : t){ 
            if(c=='(')s.push(1);
            else if(c=='{')s.push(2);
            else if(c=='[')s.push(3);
            else if(s.empty()){res=false; break;}
            else if(s.top()==1 && c!=')')res=false;
            else if(s.top()==2 && c!='}')res=false;
            else if(s.top()==3 && c!=']')res=false;
            else s.pop();
        }
        if(s.size()!=0)return false;
        return res;
        
    }
};
