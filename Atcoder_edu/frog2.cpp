#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1,n,a,b,m,K;
    cin>>n>>K;
    vector<ll> ar(n+1,0),dp(n+1,1e10);
    for(ll i=1;i<=n;i++)
        cin>>ar[i];
    /*
    State
    dp[i]: Denotes the minimum cost to reach the ith Stone
    Recurrence
    dp[i]=min(dp[i-1]+|ar[i]-ar[i-1]|,dp[i-2]+|ar[i]-ar[i-2]|,....dp[i-k]+|ar[i]-ar[i-k]|) 
    */
    dp[1]=0;
    for(ll i=2;i<=n;i++){
        for(ll k=1;k<=min(K,i-1);k++){
            dp[i]=min(dp[i],dp[i-k]+abs(ar[i-k]-ar[i]));
        }
    }
    cout<<dp[n];
    return 0;
}
