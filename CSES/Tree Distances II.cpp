#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

vector<ll> ans(2e5+1,0);

void dfs1(ll s, ll par, vector<ll> g[], vector<ll> &nodes, vector<ll> &sumdist){
	nodes[s] = 1;
	for(auto i : g[s]){
		if(i != par){
			dfs1(i,s,g,nodes,sumdist);
			nodes[s] += nodes[i];
			sumdist[s] += nodes[i] + sumdist[i];
		}
	}
}
void dfs2(ll s, ll par, vector<ll> g[], vector<ll> &nodes){
	for(auto i : g[s]){
		if(i != par){
			ans[i] = nodes[1] - nodes[i] - nodes[i] + ans[s];
			dfs2(i,s,g,nodes);
		}
	}
}
void solve(){
	ll n;
	cin >> n;
	vector<ll> g[n+1],nodes(n+1,0),sumdist(n+1,0);
	for(ll i=0;i<n-1;i++){
		ll a,b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs1(1,1,g,nodes,sumdist);
	ans[1] = sumdist[1];
	dfs2(1,1,g,nodes);
	for(ll i=1;i<=n;i++)
	cout << ans[i] << " ";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

