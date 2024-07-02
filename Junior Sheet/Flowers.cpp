#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll MOD = 1e9 + 7;

ll solve(ll i, ll k, vector<ll> &dp){
	if(i==0){
		dp[i] = 1;
		return 1;
	}
	if(i<0)
	return 0;
	if(dp[i] != -1)
	return dp[i];
	ll res = 0;
	res = (solve(i-1,k,dp) + solve(i-k,k,dp)) % MOD;
	dp[i] = res;
	return res;
}

void solve(){
	ll t,k;
	cin >> t >> k;
	vector<ll> dp(1e5+1,-1),pr(1e5+1,0);
	for(ll i=1;i<=1e5;i++)
	solve(i,k,dp);
	for(ll i=1;i<=1e5;i++){
		pr[i] = (pr[i-1] + dp[i]) % MOD;
	}
	while(t--){
		ll a,b;
		cin >> a >> b;
		ll ans = (pr[b] - pr[a-1] + MOD)%MOD;
		cout << ans << "\n";
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

