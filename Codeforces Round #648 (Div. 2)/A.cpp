#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m;
	ll c = 0, r= 0;
	cin >> n >> m;
	vector<vector<ll>> ar(n+1,vector<ll>(m+1,0));
	for(ll i=1;i<=n;i++){
		ll uc = 0;
		for(ll j=1;j<=m;j++){
			cin >> ar[i][j];
			if(!ar[i][j]) uc++;
		}
		if(uc == m)
		r++;
	}
	for(ll j=1;j<=m;j++){
		ll uc = 0;
		for(ll i=1;i<=n;i++){
			if(!ar[i][j]) uc++;
		}
		if(uc == n)
		c++;
	}
	ll ans = min(r,c);
	if(ans%2)
	cout << "Ashish";
	else
	cout << "Vivek";
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

