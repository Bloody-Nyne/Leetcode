class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> mp;
        for(auto it: adjacentPairs){
            int u = it[0];
            int v = it[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        int root = 0;
        for(auto it: mp){
            if(it.second.size() == 1){
                root = it.first;
                break;
            }
        }
        vector<int> ans;
        dfs(root,1e9,ans,mp);
        return ans;
    }
private:
    void dfs(int node,int prev, vector<int>& ans, unordered_map<int,vector<int>>& mp){
        ans.push_back(node);
        for(auto it: mp[node]){
            if(it != prev) dfs(it,node,ans,mp);
        }
    }
};