class Solution {
public:


    int dsu[1001];
    int find(int a){
        return dsu[a] < 0 ? a : dsu[a] = find(dsu[a]);
    }

    void merge(int a, int b){
        a = find(a), b = find(b);
        if(a != b) dsu[a] = b;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        //cost, idx
        fill(dsu, dsu + 1001, -1);
        vector<tuple<int,int,int>> edges; 

        for(int i = 0; i < (int) points.size(); i++){ 
            for(int j = i + 1; j < points.size(); j++){ 
                int cost = abs(points[i][0]-points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                edges.push_back({cost, i, j});
    
            }
        }

        sort(edges.begin(), edges.end()); 
        int cost = 0; 
        for(auto edge : edges) {
            auto [c, i, j] = edge; 
            int par1 = find(i);
            int par2 = find(j);
            if(par1!=par2){ 
                cost+=c; 
                merge(i,j);
            }
        }
        return cost;
    }

   

};
