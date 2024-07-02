#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,ans = 0;
	cin >> n;
	vector<ll> ar(n+1,0), tar(n+1,-1e9);
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	for(ll i=30;i>=1;i--){
		for(ll j=1;j<=n;j++){
			if(ar[j]<=i)
			tar[j] = ar[j];
			else
			tar[j] = -1e9;
		}
		ll cmax=0,umax = 0;
		for(ll j=1;j<=n;j++){
			cmax += tar[j];
			umax = max(umax,cmax);
			cmax = max(cmax,0ll);
		}
		//cout << ans << "\n";
		ans = max(ans,umax-i);
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

