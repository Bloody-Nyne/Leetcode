class Solution {
private:
    void dfs(int row,int col,int n,int m,vector<vector<int>>& vis,vector<vector<char>>& grid){
    vis[row][col] = 1;
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    for(int i=0;i<4;i++){
        int nrow = row+delrow[i];
        int ncol = col + delcol[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
            dfs(nrow,ncol,n,m,vis,grid);
        }
    }
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int islands = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    islands++;
                    dfs(i,j,n,m,vis,grid);
                }
            }
        }
        return islands;
    }
};