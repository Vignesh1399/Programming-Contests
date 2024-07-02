#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void dfs(vector<ll> g[], ll s, vector<ll> &d, vector<long double> &prob, long double &ans){
	bool enter=1;
	for(auto i: g[s]){
		if(d[i] == -1){
			enter = 0;
			d[i] = d[s] + 1;
			ll child = (s==1)? sz(g[s]):sz(g[s])-1; 
			prob[i] = (prob[s] * 1.0)/child;
			dfs(g,i,d,prob,ans);
		}
	}
	if(enter)
	ans = ans + d[s]*prob[s];
}

void solve(){
	ll n,a,b;
	cin >> n;
	vector<ll> g[n+1];
	vector<ll> d(n+1,-1);
	vector<long double> prob(n+1,1.0);
	for(ll i=1;i<n;i++){
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	long double ans = 0;
	d[1] = 0;
	dfs(g,1ll,d,prob,ans);
	cout << setprecision(10) << fixed ;
	cout << ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

