//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> vis(n,0);
        return solve(0,vis,graph,n,m);
    }
private:
    bool solve(int node,vector<int>& vis,bool graph[101][101],int n,int m){
        if(node == n) return true;
        for(int i=1;i<=m;i++){
            if(isSafe(i,node,vis,graph,n)){
                vis[node] = i;
                if(solve(node+1,vis,graph,n,m) == true)
                    return true;
                else
                    vis[node] = 0;
            }
        }
        return false;
    }
    bool isSafe(int color,int node,vector<int>& vis,bool graph[101][101],int n){
        for(int k=0;k<n;k++){
            if(k != node && graph[k][node] == 1 && vis[k] == color) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends