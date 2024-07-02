#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll ans = 0;
void dfs(ll s, ll par, vector<ll> g[], vector<ll> &size, vector<ll> &dp){
	size[s] = 1;
	for(auto to : g[s]){
		if(to == par) continue;
		dfs(to,s,g,size,dp);
		size[s] += size[to];
		dp[s] += dp[to];
	}
	dp[s] += size[s];	
}

void dfsreroot(ll s, ll par, vector<ll> g[], vector<ll> &size, vector<ll> &dp){
	ans = max(ans,dp[s]);
	for(auto to : g[s]){
		if(to == par) continue;
		dp[s] -= dp[to];
		dp[s] -= size[to];
		size[s] -= size[to];
		dp[to] += dp[s];
		dp[to] += size[s];
		size[to] += size[s];
		dfsreroot(to,s,g,size,dp);
		size[to] -= size[s];
		dp[to] -= size[s];
		dp[to] -= dp[s];
		size[s] += size[to];
		dp[s] += size[to];
		dp[s] += dp[to];
	}
}
void solve(){
	ll n;
	cin >> n;
	vector<ll> g[n+1],size(n+1,0),dp(n+1,0);
	for(ll i=0;i<n-1;i++){
		ll a,b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1,1,g,size,dp);
	/*
	for(ll i=1;i<=n;i++)
	cout << i << " " << dp[i] << "\n";
	*/
	dfsreroot(1,1,g,size,dp);
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

