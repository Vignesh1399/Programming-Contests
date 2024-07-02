#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll skip(ll p, ll i, vector<vector<ll>> &dp,vector<ll> &ar, ll n){
	if(i>=n)
	return 0;
	if(dp[i][p] != -1)
	return dp[i][p];
	ll ans = 1e10;
	if(p == 0){
		if(ar[i]){
			ans = 1 + skip(!p,i+1,dp,ar,n);
			if(i+1<n && ar[i+1])
			ans = min(ans,2 + skip(!p,i+2,dp,ar,n));
			else if(i+1<n)
			ans = min(ans,1 + skip(!p,i+2,dp,ar,n));
			else
			ans = min(ans,1 + skip(!p,i+1,dp,ar,n));
		}
		else{
			ans = skip(!p,i+1,dp,ar,n);
			if(i+1<n && ar[i+1])
			ans = min(ans,1 + skip(!p,i+2,dp,ar,n));
			else if(i+1<n)
			ans = min(ans,skip(!p,i+2,dp,ar,n));
		}
	}
	else{
		ans = skip(!p,i+1,dp,ar,n);
		ans = min(ans,skip(!p,i+2,dp,ar,n));
	}
	dp[i][p] = ans;
	return ans;
}

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n);
	for(auto &i : ar)
	cin >> i;
	vector<vector<ll>> dp(n+1,vector<ll>(2,-1));
	ll ans = skip(0,0,dp,ar,n);
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

