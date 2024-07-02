#include <bits/stdc++.h>
#define ll int
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
 
ll explore(ll i, ll j, vector<vector<ll>> &dp, vector<vector<ll>> &path,vector<pair<ll,ll>> g[]){
	if(i==1){
		if(j == 1)
		return 0;
		else
		return 1e9+1;
	}
	if(j<1)
	return 1e9+1;
	if(dp[i][j] != -1)
	return dp[i][j];
	ll ans = 1e9+1;
	for(auto x : g[i]){
		dp[x.first][j-1] = explore(x.first,j-1,dp,path,g);
		if(dp[x.first][j-1] + x.second <= ans){
			ans = dp[x.first][j-1] + x.second;
			path[i][j] = x.first;
		}
	}
	dp[i][j] = ans;
	return ans;
}

void solve(){
	ll n,m,t;
	cin >> n >> m >> t;
	vector<pair<ll,ll>> g[n+1];
	for(ll i = 1;i<=m;i++){
		ll u,v,time;
		cin >> u >> v >> time;
		g[v].pb({u,time});
	}
	vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1)),path(n+1,vector<ll>(n+1,0));
	ll max_len = 0;
	for(ll i=1;i<=n;i++){
		if(explore(n,i,dp,path,g) <= t)
		max_len = i;
		//cout << n << " " << i << " " << dp[n][i] << "\n";
	}
	vector<ll> ans;
	ll cur = n;
	cout << max_len << "\n";
	while(max_len){
		ans.pb(cur);
		cur = path[cur][max_len];
		max_len--;
	}
	reverse(ans.begin(),ans.end());
	for(auto i : ans)
	cout << i << " ";
}

int32_t main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

