class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m];
        //{{row,col},time} -> for queue
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        int minTime=0;
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            q.pop();
            minTime=max(minTime,time);
            
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow < n && nrow >= 0 && ncol >= 0 && ncol <m && vis[nrow][ncol] != 2 &&
                   grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 2;
                    q.push({{nrow,ncol},time+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return minTime;
    }
};