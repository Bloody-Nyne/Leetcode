//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(arr.begin(),arr.end());
        backTrack(0,arr,temp,ans,k);
        return ans;
    }
private:
    void backTrack(int ind,vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans,int target){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            if(i != ind && nums[i] == nums[i-1]) continue;
            if(nums[i] > target) break;
            temp.push_back(nums[i]);
            backTrack(i+1,nums,temp,ans,target-nums[i]);
            temp.pop_back();
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends