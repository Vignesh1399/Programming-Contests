#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	map<ll,ll> m;
	vector<ll> ar(n+1,0);
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
		m[ar[i]]++;
	}
	ll ans=0;
	for(ll i=2;i<=2*n;i++){
		ll temp = 0;
		for(ll j=1;j<=n;j++){
			ll k = i-j;
			if(k==j) temp += m[k];
			else temp += min(m[k],m[j]);
		}
		ans = max(ans,temp/2);
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

