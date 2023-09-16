class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int minDiff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i=0;i<4;i++){
                int newr = r + dr[i];
                int newc = c + dc[i];
                if(newr >= 0 && newr < n && newc >= 0 && newc < m){
                    int diff = max(abs(heights[r][c] - heights[newr][newc]),minDiff);
                    if(diff < dist[newr][newc]){
                        dist[newr][newc] = diff;
                        pq.push({diff,{newr,newc}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};