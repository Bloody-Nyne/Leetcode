class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n,1e9);
        dist[src] = 0;
        queue<pair<int,pair<int,int>>> q;
        // {stops,{city,price}}
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int city = it.second.first;
            int price = it.second.second;
            
            if(stops > k) continue;
            for(auto it: adj[city]){
                int adjCity = it[0];
                int adjPrice = it[1];
                if(price + adjPrice < dist[adjCity] && stops <= k){
                    dist[adjCity] = price + adjPrice;
                    q.push({stops + 1,{adjCity,price + adjPrice}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};