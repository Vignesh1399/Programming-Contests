#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

/*
Consider floyd - warshall algorithm for shortest paths
where it computes all pair shortest paths using vertices from only 1...k
similarly, we should compute sum of shortest paths before 1st vertex is removed,
before second vertex is removed and so on...
Trick: Consider the first vertex to be removed as the last vertex to be included 
in the augumenting path of all - pair shortest path algorithm
*/

void solve(){
	ll n,x,ni,nj,nk;
	cin >> n;
	ll w[n+1][n+1],number_map[n+1];
	vector<ll> temp;
	vector<vector<ll>> dp(n+1,vector<ll>(n+1,1e10));
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			cin >> w[i][j];
			dp[i][j] = w[i][j];
		}
	}
	for(ll i=0;i<n;i++){
		cin >> x;
		number_map[n-i] = x;
	}
	for(ll k=1;k<=n;k++){
		ll sum = 0;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				ni = number_map[i], nj = number_map[j], nk = number_map[k];
				dp[ni][nj] = min(dp[ni][nj],dp[ni][nk] + dp[nk][nj]);
				// Add to sum only if current vertex is not removed
				if(i<=k && j<=k)
				sum += dp[ni][nj];
			}
		}
		temp.pb(sum);
	}
	reverse(temp.begin(),temp.end());
	for(ll i=0;i<n;i++)
	cout<<temp[i]<<" ";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

