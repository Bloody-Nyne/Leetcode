class Solution {
private:
    int dfs(int row,int col,int n,int m,vector<vector<int>>& vis,vector<vector<int>>& grid){
        vis[row][col] = 1;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        int count = 1;
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                count += dfs(nrow,ncol,n,m,vis,grid);
            }
        }
        return count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int maxArea = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count = 0;
                if(!vis[i][j] && grid[i][j] == 1){
                    maxArea = max(maxArea,dfs(i,j,n,m,vis,grid));
                }
            }
        }
        return maxArea;
    }
};