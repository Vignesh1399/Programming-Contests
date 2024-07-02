#include "bits/stdc++.h"
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
void solve(){
	ll n,m,x,y;
	cin >> n >> m >> x >> y;
	vector<ll> temp;
	for(ll j=y;j<=m;j++)
	temp.pb(j);
	for(ll j=1;j<y;j++)
	temp.pb(j);
	for(ll i=x;i<=n;i++){
		for(auto j : temp)
		cout << i << " " << j << "\n";
		reverse(temp.begin(),temp.end());
	}
	for(ll i=1;i<x;i++){
		for(auto j : temp)
		cout << i << " " << j << "\n";
		reverse(temp.begin(),temp.end());
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

