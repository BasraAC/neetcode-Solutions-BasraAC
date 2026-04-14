class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s; 

        for(auto token : tokens){     
            if(token=="+"){
                int first = s.top();s.pop();
                int second = s.top(); s.pop();
                s.push( second + first);
            }
            else if(token=="-"){
                int first = s.top();s.pop();
                    int second = s.top(); s.pop();
                    s.push( second - first);
            }
            else if(token=="/"){
                    int first = s.top();s.pop();
                    int second = s.top(); s.pop();
                    s.push( second / first);
             }
            else if(token=="*"){
                int first = s.top();s.pop();
                int second = s.top(); s.pop();
                s.push( second * first);
            }
            else{
                s.push(stoi(token));
            }
        }
     
        return s.top();
        
    }
};
