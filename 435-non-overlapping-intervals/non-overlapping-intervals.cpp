class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[1] < b[1];
        });
        int cnt = 0;
        int mini = -1e9;
        for(int i=0;i<n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start >= mini){
                mini = end;
            }
            else{
                cnt++;
            }
        }
        return  cnt;
    }
};