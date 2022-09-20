class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
	if(size(A) < size(B)) A.swap(B);   // ensures dp length is min(M, N)
	int m = size(A), n = size(B), ans = 0, dp[2][n+1]; 
	memset(dp, 0, sizeof dp);
	for(int i = m-1, cur=i&1, next=!(i&1); ~i; i--, cur ^= 1, next ^= 1)  
		for(int j = n-1; ~j; j--) 
			dp[cur][j] = A[i] == B[j] ? dp[next][j+1] + 1 : 0,
			ans = max(ans, dp[cur][j]);
		
	return ans;
   }
};