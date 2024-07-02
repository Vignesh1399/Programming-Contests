#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void makegraph(vector<ll> &ar, vector<ll> g[],ll n){
	for(ll i=1;i<=n;i++){
		g[i].pb(i-ar[i]);
	}
}

void dfs(vector<ll> g[], ll s, vector<ll> &v, vector<ll> &start){
	v[s] = 1;
	for(auto i:g[s]){
		if(!v[i])
			dfs(g,i,v,start);
		if(v[i] == 1)
			start.pb(i);
	}
	v[s] = 2;
}

void solve(){
	ll n;
	cin >> n;
	vector<ll> g[n+1];
	vector<ll> ar(n+1,0), v(n+1,0), start;
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	makegraph(ar,g,n);
	dfs(g,1,v,start);
	ll x = start[0];
	vector<ll> ans;
	do{
		ans.pb(x);
		x -= ar[x];
	}while(x!=start[0]);
	cout<<sz(ans)<<"\n";
	for(auto i:ans)
	cout<<i<<" ";
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

