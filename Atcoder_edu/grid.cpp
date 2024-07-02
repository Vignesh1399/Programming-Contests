#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
using namespace std;
int main() {
    ll H,W;
    char ch;
    cin>>H>>W;
    vector<vector<ll>> dp(H+1,vector<ll> (W+1,0));
    /*
    State
    dp[i][j]: Denotes the number of ways to reach cell (i,j)
    Recurrence:
    dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod)%mod
    i.e we can arrive at this cell from the left or from the top cell
    */
    dp[1][1] = 1;
    for(ll i=1;i<=H;i++){
        for(ll j=1;j<=W;j++){
            cin>>ch;
            if(ch != '#' && !(i==1 && j==1)){
                dp[i][j] = (dp[i][j-1]%mod + dp[i-1][j]%mod)%mod;
            }
        }
    }
    cout<<dp[H][W];
	return 0;
}
