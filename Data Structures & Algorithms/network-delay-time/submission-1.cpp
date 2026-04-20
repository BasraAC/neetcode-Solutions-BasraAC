class Solution {
public:
    const long long LLINF = 0x3f3f3f3f3f3f3f3f;

    vector<long long> dijkstra(int n, int s, const vector<vector<pair<int,long long>>> &adj){
        vector<long long> dist(n + 1, LLINF);
        dist[s] = 0;

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        pq.push({0, s});

        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();

            if(d != dist[u]) continue;

            for(auto &ed : adj[u]){
                int v = ed.first;
                long long w = ed.second;

                if(dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,long long>>> adj(n + 1);

        for(auto &edge : times){
            int u = edge[0], v = edge[1], t = edge[2];
            adj[u].push_back({v, t});
        }

        vector<long long> dist = dijkstra(n, k, adj);

        long long res = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == LLINF) return -1;
            res = max(res, dist[i]);
        }

        return (int)res;
    }
};