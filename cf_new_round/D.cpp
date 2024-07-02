#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

vector<ll> cyc,v,h,p;

void dfs(ll s, ll par, vector<ll> g[]){
	v[s] = 1;
	h[s] = h[par] ^ 1;
	p[s] = par;
	for(auto to : g[s]){
		if(to != par && v[to]){
			ll x = s;
			while(x != to){
				cyc.pb(x);
				x = p[x];
			}
			cyc.pb(to);
			cout << 2 << "\n";
			cout << sz(cyc) << "\n";
			for(ll i=sz(cyc)-1;i>=0;i--)
			cout << cyc[i] << " ";
			exit(0);
		}
		else if(!v[to])
		dfs(to,s,g);
	}
}

void solve(){
	ll n,m,k,a,b;
	cin >> n >> m >> k;
	v.resize(n+1,0);
	h.resize(n+1,0);
	p.resize(n+1,1);
	vector<ll> g[n+1];
	for(ll i=1;i<=m;i++){
		cin >> a >> b;
		if(a>k || b>k)
		continue;
		g[a].pb(b);
		g[b].pb(a);
	}
	for(ll i=1;i<=k;i++){
		if(!v[i])
		dfs(i,i,g);
	}
	vector<ll> odd,even,ans;
	for(ll i=1;i<=k;i++){
		if(h[i])
		odd.pb(i);
		else
		even.pb(i);
	}
	if(sz(odd)>sz(even))
	ans = odd;
	else
	ans = even;
	cout << 1 << "\n";
	for(ll i=0;i<(k+1)/2;i++)
	cout << ans[i] << " ";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

