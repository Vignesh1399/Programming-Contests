#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,s,a,b;
	cin >> n >> s;
	vector<ll> g[n+1];
	for(ll i=0;i<n-1;i++){
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	ll l = 0;
	for(ll i=0;i<n;i++){
		l += (sz(g[i+1]) == 1ll);
	}
	double ans = (2.0*s)/l;
	cout << setprecision(10) << fixed << showpoint;
	cout << ans ;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

