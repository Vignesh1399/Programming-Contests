#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,ans=0;
	cin >> n;
	vector<ll> ar(n+1,0),br(n+1,0),pa(n+1,0),pb(n+1,0);
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
		pa[i] = pa[i-1] + ar[i];
	}
	for(ll i=1;i<=n;i++){
		cin >>br[i];
		pb[i] = pb[i-1] + br[i];
		if(pa[i-1] == pb[i-1] && ar[i] == br[i])
		ans += ar[i];
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

