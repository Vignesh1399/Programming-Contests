#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll ans = 1;
void dfs(ll s, vector<ll> g[],vector<ll> &mn, vector<ll> &mx){
	mn[s] = 1e9;
	mx[s] = 1;
	for(auto i : g[s]){
		dfs(i,g,mn,mx);
		mn[s] = min(mn[i]+1,mn[s]);
		mx[s] = max(mx[s],mx[i]+1); 
	}
	if(sz(g[s]) == 0){
		mn[s] = 1;
	}
}


void solve(){
	ll n;
	cin >> n;
	vector<ll> g[n+1];
	vector<ll> mn(n+1,1e9),mx(n+1,0);
	for(ll i=0;i<n-1;i++){
		ll a,b;
		cin >> a >> b;
		g[a].pb(b);
	}
	ll ans = 1;
	dfs(1,g,mn,mx);
	for(ll i=1;i<=n;i++){
		if(i == 1 || sz(g[i]) == 1)
		ans = max(ans,mn[i]-1);
		if(sz(g[i])>1)
		ans = max({ans,mx[i]});
	}
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

