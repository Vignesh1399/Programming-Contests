#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,ans=0;
	cin >> n;
	vector<ll> ar(n+1,0),br(n+1,0);
	ll am=1e10,bm=1e10;
	for(ll i=1;i<=n;i++){
	cin >> ar[i];
	am = min(am,ar[i]);
	}
	for(ll i=1;i<=n;i++){
	cin >> br[i];
	bm = min(bm,br[i]);
	}
	for(ll i=1;i<=n;i++){
		ll ad = ar[i] - am;
		ll bd = br[i] - bm;
		ans += max(ad,bd);
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

