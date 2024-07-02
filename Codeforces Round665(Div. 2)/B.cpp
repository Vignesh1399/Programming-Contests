#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll k=1;
void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n+1,0),br;
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	for(ll i=2;i<=n;i++){
		br.pb(ar[i]-ar[i-1]);
	}
	ll c = 1;
	ll ans = 1;
	for(ll i=1;i<sz(br);i++){
		if(br[i] == br[i-1])
		c++;
		else
		c = 1;
		ans = max(ans,c);
		//cout << br[i] << " ";
	}
	cout << "Case #"<<k++<<": " << ans+1ll << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

