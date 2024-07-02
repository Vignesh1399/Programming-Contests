
// Problem: E - Through Path
// Contest: AtCoder - AtCoder Beginner Contest 187
// URL: https://atcoder.jp/contests/abc187/tasks/abc187_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll add = 0;
void dfs(ll s, ll p, vector<ll> g[], vector<ll> &par){
	par[s] = p;
	for(auto i : g[s]){
		if(i != p)
		dfs(i,s,g,par);
	}
}
void dfsupd(ll s, ll p, vector<ll> g[], vector<ll> &dp){
	for(auto i : g[s]){
		if(i != p){
			dp[i] += dp[s];
			dfsupd(i,s,g,dp);
		}
	}
}

void solve(){
	ll n,q;
	cin >> n;
	vector<ll> g[n+1];
	vector<ll> par(n+1,0),dp(n+1,0);
	vector<pair<ll,ll>> edge(n+1);
	for(ll i=0;i<n-1;i++){
		ll a,b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
		edge[i+1] = {a,b};
	}
	dfs(1,1,g,par);
	cin >> q;
	add = 0;
	while(q--){
		ll t,e,x;
		cin >> t >> e >> x;
		if(t == 1){
			if(edge[e].F == par[edge[e].S]){
				dp[edge[e].S] -= x;
				add += x;
			}
			else
			dp[edge[e].F] += x;
		}
		else{
			if(par[edge[e].F] == edge[e].S){
				dp[edge[e].F] -= x;
				add += x;
			}
			else
			dp[edge[e].S] += x;
		}
	}
	dfsupd(1,1,g,dp);
	for(ll i=1;i<=n;i++)
	cout << dp[i] + add << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

