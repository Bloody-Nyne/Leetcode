class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0)); //visited array
        queue<pair<int,int>> q;
        
        //check for row's boundary 1's
        for(int j=0;j<m;j++){
            //check for 1st row
            if(grid[0][j] == 1){
                q.push({0,j});
                vis[0][j] = 1;
            }
            //check for last row
            if(grid[n-1][j] == 1){
                q.push({n-1,j});
                vis[n-1][j] = 1;
            }
        }
        //check for col's boundary 1's
        for(int i=0;i<n;i++){
            //check for 1st col
            if(grid[i][0] == 1){
                q.push({i,0});
                vis[i][0] = 1;
            }
            //check for last col
            if(grid[i][m-1] == 1){
                q.push({i,m-1});
                vis[i][m-1] = 1;
            }  
        }
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] &&
                  grid[nrow][ncol] == 1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};