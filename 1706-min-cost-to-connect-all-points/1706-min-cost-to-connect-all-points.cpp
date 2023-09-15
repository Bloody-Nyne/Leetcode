class Solution {
    int MST(int V,vector<vector<int>> *adj){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<bool> visited(V,false);
        vector<int> cost(V,1e8);
        cost[0]=0;
        int ans=0;
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            int u=t.second,wt=t.first;
            if(visited[u]){continue;}
            visited[u]=true;
            ans+=wt;
            for(auto x : adj[u]){
                int v=x[0],e=x[1];
                if(cost[v] > e){
                    cost[v]=e;
                    pq.push({cost[v],v});
                }
            }
        }
        return ans;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();
        vector<vector<int>> adj[V];
        for(int i=0;i<V;i++){
            int x1=points[i][0],y1=points[i][1];
            for(int j=0;j<V;j++){
                if(j == i){continue;}
                int x2=points[j][0],y2=points[j][1];
                int val=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,val});
            }
        }
        return MST(V,adj);
    }
};