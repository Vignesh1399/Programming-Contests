#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m;
	cin >> n >> m;
	ll ans = 0;
	vector<vector<ll>> ar(n+1,vector<ll> (m+1,0));
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++)
		cin >> ar[i][j];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			vector<ll> dat;
			if(ar[i][j] == -1) continue;
			//row;
			dat.pb(ar[i][j]);
			ar[i][j] = -1;
			if(m-j+1 != j){
			dat.eb(ar[i][m-j+1]);
			ar[i][m-j+1] = -1;
			}
			if(n-i+1 != i){
			dat.eb(ar[n-i+1][j]);
			ar[n-i+1][j] = -1;
			}
			if(ar[n-i+1][m-j+1] != -1){
			dat.eb(ar[n-i+1][m-j+1]);
			ar[n-i+1][m-j+1] = -1;
			}
			sort(dat.begin(),dat.end(),greater<ll>());
			ll mx = 0;
			if(sz(dat)%2)
			mx = dat[sz(dat)/2];
			else
			mx = (dat[sz(dat)/2] + dat[sz(dat)/2-1])/2;
			for(auto it : dat)
			ans += abs(mx-it);
		}
	}
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

