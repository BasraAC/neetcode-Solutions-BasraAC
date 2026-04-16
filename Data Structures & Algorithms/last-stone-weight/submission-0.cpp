class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int> hp; 
        for(int s : stones)hp.insert(s);
        while(hp.size()!=1){ 
            auto it = prev(hp.end());
            int x1 = *it;
            hp.erase(it);
            it = prev(hp.end());
            int x2 = *it;
            hp.erase(it);
            hp.insert(abs(x1-x2));
        }
        return *prev(hp.end());
    }
};