class Solution {
private:
    void dfs(int node,vector<int>& vis,vector<int> adj[]){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N=isConnected.size();
        vector<int> adj[N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(N,0);
        int count=0;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,adj);
            }
        }
        return count;
    }
};