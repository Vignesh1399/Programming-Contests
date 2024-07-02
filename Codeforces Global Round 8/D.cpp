#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,ans=0;
	cin >> n;
	vector<ll> ones(21,0);
	for(ll i=1;i<=n;i++){
		ll a;
		cin >> a;
		for(ll j=0;j<=20;j++)
		ones[j] += (a>>j) & 1;
	}
	for(ll i=1;i<=n;i++){
		ll term = 0;
		for(ll j=0;j<=20;j++){
			ll bit = ones[j]>0;
			term += (1<<j) * bit;
			--ones[j];
		}
		ans += term * term;
	}
	cout << ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

