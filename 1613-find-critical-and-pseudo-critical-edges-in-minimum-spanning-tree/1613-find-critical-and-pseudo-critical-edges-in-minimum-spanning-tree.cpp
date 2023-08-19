class DSU { //DSU by Rank -> Higher rank is the parent
public:
    vector<int> parent, rank;
    DSU(int n){
        parent.resize(n, 0);
        rank.resize(n, 0);
        for(int i=0;i<n;i++) parent[i] = i; //Everyone is their own parent initially
    }

    int find(int x){
        return parent[x] = parent[x] == x ? x : find(parent[x]); //Recursion func -> Go find parent of parent & keep assigning values
    }
    
    bool Union(int x, int y){
        int xset = find(x), yset = find(y); //Find parents of both nodes -> to know which set they belong
        if(xset != yset){ // If they have differnt parents (i.e, belong to differnt sets)
            rank[xset] < rank[yset] ? parent[xset] = yset : parent[yset] = xset; //Whose rank is greater -> set him as parent of the other
            rank[xset] += rank[xset] == rank[yset]; //If their ranks are same make xset the parent -> rank[xset]+1
            return true;
        }
        return false; // If they are already in same set (i.e, have same parent)
    }
};

class Solution {
public:
    int GetMst(const int n,const vector<vector<int>>& edges,int excludeEdge = -1, int includeEdge = -1){
        DSU dsu(n);
        int wt = 0;
        if(includeEdge != -1){
            wt += edges[includeEdge][2];
            dsu.Union(edges[includeEdge][0],edges[includeEdge][1]);
        }
        for(int i=0;i<edges.size();++i){
            if(i == excludeEdge) continue; // Exclude this node from mst
            const auto &it = edges[i];
            if(dsu.find(it[0]) == dsu.find(it[1])) continue;
            dsu.Union(it[0],it[1]);
            wt += it[2];
        }
        for (int i = 0; i < n; ++i) {
            if (dsu.find(i) != dsu.find(0)) return 1e9+7;
        }
        return wt;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++){
            edges[i].push_back(i); //Push in the indexes->to get them as output
        }
        sort(edges.begin(),edges.end(),[](const vector<int>& a,const vector<int>& b){
            return  a[2] < b[2]; // sort according to their weights in ascending order
        });
        int original_mst = GetMst(n,edges,-1);
        vector<int> critical,pcritical;
        for(int i=0;i<edges.size();++i){
            if(original_mst < GetMst(n,edges,i)){ // Exclude the current node for critical
                critical.push_back(edges[i][3]); // get indexes as output
            }
            else if(original_mst == GetMst(n,edges,-1,i)){ // include the current node for pseudo-critical
                pcritical.push_back(edges[i][3]); // get indexes of nodes as output
            }
        }
        return {critical,pcritical};
    }
};