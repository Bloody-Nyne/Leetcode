//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int n, int k, vector<int> &nums) {
        sort(nums.begin(),nums.end());
        int low = 1;
        int high = nums[n-1] - nums[0];
        int ans = -1;
        while(low <= high){
            int mid = (low+high) >> 1;
            if(isPossible(nums,mid,k)){
                ans = max(ans,mid);
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
private:
    bool isPossible(vector<int>& nums,int minDist,int cows){
        int cnt = 1,lastDist = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] - lastDist >= minDist){
                cnt++;
                lastDist = nums[i];
                if(cnt == cows) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends