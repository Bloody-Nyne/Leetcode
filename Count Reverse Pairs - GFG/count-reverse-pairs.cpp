//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countRevPairs(int n, vector<int> arr) {
        int cnt = 0;
        return mergeSort(arr,0,n-1,cnt);
    }
private:
    int mergeSort(vector<int>& nums,int left,int right,int& cnt){
        if(left >= right) return 0;
        int mid = (left+right)/2;
        mergeSort(nums,left,mid,cnt);
        mergeSort(nums,mid+1,right,cnt);

        merge(nums,left,mid,right,cnt);
        return cnt;
    }
    void merge(vector<int>& nums,int left,int mid,int right,int& cnt){
        int i,j;
        j = mid+1;
        for(int i=left;i<=mid;i++){
            while(j <= right && ((long)nums[i] > 2*(long)nums[j])) j++;
            cnt += (j - (mid+1));
        }
        int *temp = new int[right+1];
        i = left;
        j = mid+1;
        int k = left;
        while(i <= mid && j <= right){
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            }
            else{
                temp[k++] = nums[j++];
            }
        }
        while(i <= mid){
            temp[k++] = nums[i++];
        }
        while(j <= right){
            temp[k++] = nums[j++];
        }
        for(i=left;i<=right;i++){
            nums[i] = temp[i];
        }
        delete[] temp;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends