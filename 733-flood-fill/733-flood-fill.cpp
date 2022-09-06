class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& ans,
     vector<vector<int>>& image,int color,int delrow[],int delcol[],int ini){
        ans[row][col]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
            image[nrow][ncol]==ini && ans[nrow][ncol] != color){
                dfs(nrow,ncol,ans,image,color,delrow,delcol,ini);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      /*  int iniColor=image[sr][sc];
        vector<vector<int>> ans=image;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        dfs(sr,sc,ans,image,color,delrow,delcol,iniColor);
        
        return ans; */
        
        //using BFS
        int iniColor=image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> ans=image;
        queue<pair<int,int>> q;
        ans[sr][sc] = color;
        q.push({sr,sc});
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                image[nrow][ncol]==iniColor && ans[nrow][ncol] != color){
                    q.push({nrow,ncol});
                    ans[nrow][ncol] = color;
                }
            }
        }
        return ans;
    }
    
    
    
    
    
    
    
};