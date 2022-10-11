class Solution {
private:
    void dfs(int node,vector<int>& vis,vector<vector<int>>& graph,vector<int>& curpath,vector<vector<int>>& ans){
        int n = graph.size();
        if(node == n-1) {
            ans.push_back(curpath);
            return;
        }
        if(vis[node]) return;
        vis[node] = 1;
        for(auto it: graph[node]){
                curpath.push_back(it);
                dfs(it,vis,graph,curpath,ans);
                curpath.pop_back();
        }
        vis[node] = 0; //backTrack
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> curpath;
        vector<int> vis(n,0);
        curpath.push_back(0);
        dfs(0,vis,graph,curpath,ans);
        
        return ans;
    }
};