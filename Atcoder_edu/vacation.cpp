#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1,n;
    cin>>n;
    vector<ll> a(n+1,0),b(n+1,0),c(n+1,0);
    ll dp[n+1][3]={
        0
    };
    for(ll i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    /*
    State
    dp[i][char j]: Denotes the maximum happiness  unitl the ith day if he performs activity j
    Recurrence
    dp[i][j]=max(dp[i-1][k]+ points/happiness for j) for all k except j
    */
    dp[1][1]=b[1];dp[1][2]=c[1];dp[1][0]=a[1];
    for(ll i=2;i<=n;i++){
        for(ll j=0;j<3;j++){
            ll points=0;
            if(j==0)
                points=a[i];
            else if(j<2)
                points=b[i];
            else
                points=c[i];
            for(ll k=0;k<3;k++){
                if(k!=j)
                    dp[i][j]=max(dp[i-1][k]+points,dp[i][j]);
            }
        }
    }
    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]));
    return 0;
}
