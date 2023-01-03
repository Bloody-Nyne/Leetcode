//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        vector<int> startTime,endTime, profit;
        for(int i=0;i<intervals.size();i++){
            startTime.push_back(intervals[i][0]);
            endTime.push_back(intervals[i][1]);
            profit.push_back(intervals[i][2]);
        }
        
        map<int, int> times;
        unordered_map<int, vector<pair<int, int>>> jobs;
        for (auto i = 0; i < startTime.size(); ++i) {
           times[startTime[i]] = 0;
           jobs[startTime[i]].push_back({ endTime[i], profit[i] });
        }    
        int max_profit = 0;
        for (auto it = rbegin(times); it != rend(times); ++it) {
            for (auto job : jobs[it->first]) {
                auto it = times.lower_bound(job.first);
                max_profit = max(max_profit, (it == end(times) ? 0 : it->second) + job.second);
            }
            it->second = max_profit;
        }
        return max_profit;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends