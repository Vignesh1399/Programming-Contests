#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	ll MOD = 1e9 + 7;
	cin >> n;
	vector<ll> dp(n+1,0);
	dp[0] = 1;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=6;j++){
			if(i-j >= 0)
				dp[i]  = (dp[i] + dp[i-j]) % MOD;
		}
	}
	cout << dp[n];
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

