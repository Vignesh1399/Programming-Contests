#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1,n,a,b,m;
    //cin>>t;
    while(t--){
		
    }
    return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	ll n,W,ans=0,val=1e5;
	cin>>n>>W;
	vector<ll> w(n+1),v(n+1);
    vector<vector<ll>> dp(n+1,vector<ll>(val+1,1e10));
	/*
	State
	dp[i][j]: Denotes the minimum weight of items(from 1 to i) picked in the bag having total value == j
	Recurrence
	2 choices 1: we pick the ith element, 2: we dont pick the ith element 
	The 2 choices are checked for all weights
	dp[i][j]=minimum(weight of items picked from 1 to i-1 with value == j,weight of items picked from 1 to i-1 with value == (j-value[i]) + weight[i])
	*/
	for(ll i=1;i<=n;i++)
	cin>>w[i]>>v[i];
	for(ll i=0;i<=n;i++){
        dp[i][0] = 0;
    }
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<=val;j++){
			if(v[i]>j)
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=min(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
			if(dp[i][j]<=W)
				ans=max(ans,j);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
