#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n+1,0),dp(n+1,0);
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
		dp[i] = dp[i-1] ^ i;
	}
	ll ans = ar[1];
	for(ll i=2;i<=n;i++){
		if(n/i % 2)
		ans = ans ^ dp[i-1];
		ans = ans ^ dp[n%i];
		ans = ans ^ ar[i];
	}
	cout<<ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

