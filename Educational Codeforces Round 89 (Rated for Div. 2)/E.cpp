#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll MOD = 998244353;

void solve(){
	ll n,m;
	cin >> n >> m;
	vector<ll> ar(n+1,0),br(m+1,0),suf(n+2,1e10),spos(m+2,0);
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	for(ll i=1;i<=m;i++)
	cin >> br[i];
	for(ll i=n;i>=1;i--)
	suf[i] = min(suf[i+1],ar[i]);
	ll ans = 1;
	if(suf[1] != br[1])
	ans = 0;
	for(ll i=2;i<=n;i++){
		ll pos = upper_bound(br.begin()+1,br.begin()+m+1,suf[i]) - br.begin();
		if(br[pos-1] == suf[i])
		spos[pos-1]++;
	}
	for(ll i=2;i<=m;i++)
	ans = (ans * spos[i]) % MOD;
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

