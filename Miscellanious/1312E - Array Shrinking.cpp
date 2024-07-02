#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll single_yes_no(vector<ll> &ar, vector<vector<ll>> &dp, ll i, ll j){
	if(i==j){
	dp[i][j] = ar[i];
	return ar[i];
	}
	else if(dp[i][j] != -2)
	return dp[i][j];
	for(ll x = i;x < j; x++){
		ll a = single_yes_no(ar,dp,i,x);
		ll b = single_yes_no(ar,dp,x+1,j);
		if(a == b && a>0)
		dp[i][j] = a+1;
		else
		dp[i][j] = max(-1ll,dp[i][j]);
	}
	return dp[i][j];
}

ll optimal_partition(vector<ll> &dp2, vector<vector<ll>> &dp, ll n){
	if(n==0)
	return 0;
	else if(dp2[n] != 1e10)
	return dp2[n];
	for(ll i=1;i<=n;i++){
		if(dp[i][n] != -1)
		dp2[n] = min(dp2[n],1 + optimal_partition(dp2,dp,i-1));
	}
	return dp2[n];
}

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n+1,0);
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	vector<vector<ll>> dp(n+1,vector<ll>(n+1,-2));
	single_yes_no(ar,dp,1,n);
	vector<ll> dp2(n+1,1e10);
	optimal_partition(dp2,dp,n);
	cout<<dp2[n];
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

