
// Problem: F - Close Group
// Contest: AtCoder - AtCoder Beginner Contest 187
// URL: https://atcoder.jp/contests/abc187/tasks/abc187_f
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define ll int
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m;
	cin >> n >> m;
	vector<vector<bool>> adj(n,vector<bool>(n,0));
	vector<bool> good(1<<n,1);
	vector<ll> dp(1<<n,1e3);
	dp[0] = 0;
	for(ll i=0;i<m;i++){
		ll a,b;
		cin >> a >> b;
		a--;
		b--;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	// Precompute whether all masks (all subset of nodes) are good or not
	for(ll i=0;i<(1<<n);i++){
		vector<ll> nod_msk;
		for(ll j=0;j<n;j++){
			if(1&(i>>j))
			nod_msk.eb(j);
		}
		for(ll x=0;x<sz(nod_msk);x++){
			for(ll j=x+1;j<sz(nod_msk);j++){
				if(!adj[nod_msk[x]][nod_msk[j]])
				good[i] = 0;
			}
		}
	}
	for(ll i=1;i<(1<<n);i++){
		if(good[i]){
			dp[i] = 1;
			continue;
		}
		for(ll j=i;j;j=(j-1)&i){
			dp[i] = min(dp[i],dp[i^j]+dp[j]);
		}
	}
	ll ans = dp[(1<<n)-1];
	cout << ans ;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

