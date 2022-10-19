class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1 && !grid[0][0]) return 1;
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0] = 0;
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            q.pop();
            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    int newr = r + dr;
                    int newc = c + dc;
                    if(newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 0 && 
                      1 + dis < dist[newr][newc]){
                        dist[newr][newc] = 1 + dis;
                        if(newr == n-1 && newc == n-1) return 1 + dis;
                        q.push({1 + dis,{newr,newc}});
                    }
                }
            }
        }
        return -1;
    }
};