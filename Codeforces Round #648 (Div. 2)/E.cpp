#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	ll ans = 0;
	vector<ll> ar(n+1,0);
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
		if(n<3)
		ans |= ar[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			for(ll k=j+1;k<=n;k++){
				ans = max(ans,ar[i] | ar[j] | ar[k]);
			}
		}
	}
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

