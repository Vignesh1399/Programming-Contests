#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n+1,0),br(n+1,0),pos(n+1,0),val(n+1,0);
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	for(ll i=1;i<=n;i++){
		cin >> br[i];
		pos[br[i]] = i;
	}
	for(ll i=1;i<=n;i++){
		ll x = pos[ar[i]] - i;
		if(x>=0)
		val[x]++;
		else{
			val[n+x]++;
		}
	}
	ll ans = 0;
	for(ll i=0;i<n;i++){
		ans = max(ans,val[i]);
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

