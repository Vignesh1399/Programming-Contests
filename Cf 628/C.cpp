#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,a,b,s=1,k=0;
	cin >> n;
	vector<pair<ll,ll>> edge(n+1,{0,0});
	vector<ll> deg(n+1,0);
	vector<ll> g[n+1];
	map<pair<ll,ll>,ll> m;
	for(ll i=0;i<n-1;i++){
	cin >> a >> b;
	edge[i] = {a,b};
	g[a].pb(b);
	deg[a]++;
	g[b].pb(a);
	deg[b]++;
	if(deg[a]>2)
	s = a;
	if(deg[b]>2)
	s = b;
	}
	for(auto i:g[s]){
	m[{s,i}] = ++k;
	m[{i,s}] = k;
	}
	for(ll i=0;i<n-1;i++){
		if(m[edge[i]])
		cout<<m[edge[i]] -1;
		else
		cout<<k++;
		cout<<"\n";
	}
	
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

