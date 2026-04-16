class Solution {
public:


    int dsu[6001];
    int find(int a){
        return dsu[a] < 0 ? a : dsu[a] = find(dsu[a]);
    }

    void merge(int a, int b){
        a = find(a), b = find(b);
        if(a != b) dsu[a] = b;
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        fill(dsu, dsu + 6001, -1); 
        for(auto edge : edges){
            merge(edge[0], edge[1]);
        }
        set<int> comp; 
        for(int i = 0; i < n; i++)comp.insert(find(i)); 
        return comp.size();

    }
};
