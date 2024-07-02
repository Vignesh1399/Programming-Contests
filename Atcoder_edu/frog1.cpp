#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1,n,a,b,m;
    cin>>n;
    vector<ll> ar(n+1,0),dp(n+1,0);
    for(ll i=1;i<=n;i++)
        cin>>ar[i];
    /*
    State
    dp[i]: Denotes the minimum cost to reach the ith Stone
    Recurrence
    dp[i]=min(dp[i-1]+|ar[i]-ar[i-1]|,dp[i-2]+|ar[i]-ar[i-2]|) for all i>2
    dp[1]=0;
    dp[2]=|ar[1]-ar[2]|
    */
    dp[1]=0;
    dp[2]=abs(ar[1]-ar[2]);
    for(ll i=3;i<=n;i++){
        dp[i]=min(dp[i-1]+abs(ar[i]-ar[i-1]),dp[i-2]+abs(ar[i]-ar[i-2]));
    }
    cout<<dp[n];
    return 0;
}
