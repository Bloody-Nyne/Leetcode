class Solution {
public:
    #define ll long long
    // by using -> [low,high] = [0,high] - [0,low-1]
    ll dp[20][2][2][20][20][50]; //dp[ind][tight][leadzero][evencnt][oddcnt][remainder];
    int k;
    ll solve(int ind,int tight,int leadzero,int evencnt,int oddcnt,int rem,string& str){
        if(ind == 0){
            if(evencnt == oddcnt && rem == 0) return 1;
            return 0;
        }

        if(dp[ind][tight][leadzero][evencnt][oddcnt][rem] != -1) 
            return dp[ind][tight][leadzero][evencnt][oddcnt][rem];
        
        int limit = tight ? str[str.size()-ind] - '0' : 9;
        ll ans = 0;
        for(int dig=0;dig<=limit;dig++){
            if(leadzero && dig == 0){
                ans += solve(ind-1,0,leadzero&(dig==0),0,0,0,str);
            }
            else{
                if(dig % 2 == 0){
                    ans += solve(ind-1,tight&(dig == limit),0,evencnt+1,oddcnt,(rem*10+dig)%k,str);
                }
                else{
                    ans += solve(ind-1,tight&(dig == limit),0,evencnt,oddcnt+1,(rem*10+dig)%k,str);
                }
            }
        }
        return dp[ind][tight][leadzero][evencnt][oddcnt][rem] = ans;
    }

    int numberOfBeautifulIntegers(int low, int high, int K) {
        k = K;
        memset(dp,-1,sizeof(dp));
        low--; // to make it -> [0,low-1];
        string lower = to_string(low);
        ll anslow = solve(lower.size(),1,1,0,0,0,lower);
        memset(dp,-1,sizeof(dp));
        string higher = to_string(high);
        ll anshigh = solve(higher.size(),1,1,0,0,0,higher);
        return anshigh-anslow; // [low,high] = [0,high] - [0,low-1]
    }
};