#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	if(n == 1){
		cout << 0 << "\n";
		return ;
	}
	ll ans = 1e9;
	for(ll i=0;i*i<=n;i++){
		ll x = i;
		ll y = n/(x+1) + ((n%(x+1))>0) - 1;
		ans = min(ans,x+y);
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

