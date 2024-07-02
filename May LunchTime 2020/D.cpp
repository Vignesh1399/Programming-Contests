#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll n,l;
vector<ll> g[200001];
ll timer;
vector<ll> tin(2e5+1),tout(2e5+1),depth,pa;
vector<vector<ll>> up;

void dfs(ll v, ll p){
	tin[v] = ++timer;
	pa[v] = p;
	up[v][0] = p;
	for(ll i=1;i<=l;i++){
		up[v][i] = up[up[v][i-1]][i-1];
	}
	for( auto i:g[v]){
		if(i!=p){
			depth[i] = depth[v] + 1;
			dfs(i,v);
		}
	}
	tout[v] = ++timer;
}

bool is_ancestor(ll u, ll v){
	return tin[u]<=tin[v] && tout[u]>=tout[v];
}

ll lca(ll u, ll v){
	if(is_ancestor(u,v))
	return u;
	else if(is_ancestor(v,u))
	return v;
	for(ll i=l;i>=0;--i){
		if(!is_ancestor(up[u][i],v))
			u = up[u][i];
	}
	return up[u][0];
}

void preprocess(ll root){
	//tin.resize(n+1);
	//tout.resize(n+1);
	timer = 0;
	l = ceil(log2(n+1));
	up.assign(n+1, vector<ll>(l+1));
	depth.resize(n+1,0);
	pa.resize(n+1,1);
	dfs(root,root);
}

void solve(){
	ll q,maxa=0;
	cin >> n >> q;
	vector<ll> ar(n+1,0);
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
		maxa = max(maxa,ar[i]);
	}
	for(ll i=1;i<=n;i++){
		g[i].clear();
	}
	for(ll i=0;i<n-1;i++){
		ll a,b;
		cin >> a >> b;
		//if(a>b)
		//swap(a,b);
		g[a].pb(b);
		g[b].pb(a);
		//pa[b] = a;
	}
	preprocess(1ll);
	while(q--){
		ll a,b;      
		cin >> a >> b;
		ll la = lca(a,b);
		ll d1 = depth[a] - depth[la],d2 = depth[b] - depth[la];
		ll nodes = d1 + d2 + 1;
		if(nodes>maxa)
		cout << 0;
		else{
			vector<ll> ans;
			ans.pb(ar[la]);
			while(b != la){
				ans.pb(ar[b]);
				b = pa[b];
			}
			while(a != la){
				ans.pb(ar[a]);
				a = pa[a];
			}
			ll val = 1e18;
			sort(ans.begin(),ans.end());
			for(ll i=1;i<sz(ans);i++){
				val = min(val,ans[i]-ans[i-1]);
			}
			cout << val;
		}
		cout << "\n";
	}
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

