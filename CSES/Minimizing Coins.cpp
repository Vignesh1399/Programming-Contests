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
	ll n,x;
	cin >> n >> x;
	vector<ll> c(n);
	for(auto &i : c)
		cin >> i;
	vector<ll> dp(x+1,1e9);
	dp[0] = 0;
	for(ll i=1;i<=x;i++){
		for(ll j=0;j<n;j++){
			if(i-c[j]>=0)
				dp[i] = min(dp[i-c[j]]+1,dp[i]);
		}
	}
	if(dp[x] < 1e9)
	cout << dp[x];
	else
	cout << -1;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

