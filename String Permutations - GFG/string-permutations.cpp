//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void solve(int index,string str,vector<string>& ans){
        if(index >= str.size()){
            ans.push_back(str);
            return;
        }
        for(int i=index;i<str.length();i++){
            swap(str[i],str[index]);
            solve(index+1,str,ans);
            swap(str[i],str[index]);
        }
    }
    vector<string> permutation(string str)
    {
        vector<string> ans;
        solve(0,str,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends