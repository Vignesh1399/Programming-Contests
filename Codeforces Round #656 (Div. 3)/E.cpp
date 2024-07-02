#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
bool flag = 0;
vector<ll> top;
void findDCycle(vector<pair<ll,ll>> g[], ll s, vector<ll> &v){
	v[s] = 1;
	for(auto i : g[s]){
		if(i.second == 0) continue;
		if(v[i.first] == 0)
			findDCycle(g,i.first,v);
		else if(v[i.first] == 1){
			cout <<"NO\n";
			flag = 1;
			return ;
		}
	}
	v[s] = 2;
}
void findTopsort(vector<pair<ll,ll>> g[], ll s, vector<ll> &v){
	v[s] = 1;
	for(auto i : g[s]){
		if(!v[i.first] && i.second)
			findTopsort(g,i.first,v);
	}
	top.pb(s);
}
void solve(){
	ll n,m,a,b,typ;
	cin >> n >> m;
	flag = 0;
	// vertex, type
	vector<pair<ll,ll>> g[n+1];
	vector<ll> dir;
	vector<ll> v(n+1,0);
	for(ll i=0;i<m;i++){
		cin >> typ >> a >> b;
		g[a].pb({b,typ});
		if(!typ)
		g[b].pb({a,typ});
		else
		dir.pb(a);
	}
	for(ll i=1;i<=n;i++){
		if(v[i] == 0 && !flag)
		findDCycle(g,i,v);
	}
	if(flag) return ;
	fill(v.begin(),v.end(),0);
	top.resize(0);
	for(auto i : dir){
		if(!v[i])
		findTopsort(g,i,v);
	}
	for(ll i=1;i<=n;i++)
	if(!v[i])
	findTopsort(g,i,v);
	reverse(top.begin(),top.end());
	fill(v.begin(),v.end(),0);
	cout << "YES\n";
	for(auto i : top){
		v[i] = 1;
		for(auto j : g[i]){
			if(!v[j.first])
			cout << i << " " << j.first << "\n";
		}
	}
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

