//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  private:
    void backTrack(vector<int>& arr,int target,int ind,vector<int>& temp,vector<vector<int>>& ans){
        if(ind == arr.size()){
            if(target == 0) ans.push_back(temp);
            return;
        }
        //pick up the element
        if(arr[ind] <= target){
            temp.push_back(arr[ind]);
            backTrack(arr,target-arr[ind],ind,temp,ans);
            temp.pop_back();
        }
        //not pick up the element
        backTrack(arr,target,ind+1,temp,ans);
    }
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<vector<int>> ans;
        set<int> st;
        vector<int> uv;
        
        for(int i=0; i<A.size(); i++){
            st.insert(A[i]);
        }
        
        A.clear();
        
        for ( auto m: st){
            A.push_back(m);
        }
        
        backTrack( A, B, 0, uv, ans );
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends