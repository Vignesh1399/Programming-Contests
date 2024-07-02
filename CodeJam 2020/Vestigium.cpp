#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll c = 1;

void solve(){
	ll n, trace = 0, rows = 0, cols = 0;
	cin >> n;
	vector<vector<ll>> ar(n+1,vector<ll>(n+1,0));
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			cin >> ar[i][j];
			if(i == j)
			trace += ar[i][j];
		}
	}
	for(ll i=1;i<=n;i++){
		set<ll> rs;
		for(ll j=1;j<=n;j++){
			rs.insert(ar[i][j]);
		}
		if(n != sz(rs))
		rows++;
	}
	for(ll i=1;i<=n;i++){
		set<ll> rs;
		for(ll j=1;j<=n;j++){
			rs.insert(ar[j][i]);
		}
		if(n != sz(rs))
		cols++;
	}
	cout<<"Case #"<<c++<<": "<<trace<<" "<<rows<<" "<<cols<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

