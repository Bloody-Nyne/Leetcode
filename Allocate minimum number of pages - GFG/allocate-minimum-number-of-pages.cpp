//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution {
    public:
    //Function to find minimum number of pages.
    int findPages(int nums[], int N, int M){
        if(M > N) return -1;
        int low = nums[0];
        int high = 0;
        for(int i=0;i<N;i++){
            low = min(low,nums[i]);
            high += nums[i];
        }
        int ans = 1e9;
        while(low <= high){
            int mid = (low+high) >> 1;
            if(isAllocationPossible(nums,mid,N,M)){
                ans = min(ans,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    private:
    bool isAllocationPossible(int nums[],int barrier,int n,int m){
        int pages = 0,cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i] > barrier) return false;
            if(pages + nums[i] > barrier){
                cnt++;
                pages = 0;
                pages += nums[i];
            }
            else{
                pages += nums[i];
            }
        }
        if(cnt < m) return true;
        return false;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends