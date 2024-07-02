#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll unp(ll i, ll t,vector<ll> &ar, vector<vector<ll>> & dp){
	if(t<0)
	return 1e9;
	if(i<0)
	return 0;
	if(dp[i][t] != -1)
	return dp[i][t];
	ll ans = 1e9;
	ans = min({ans,unp(i,t-1,ar,dp),abs(ar[i]-t)+unp(i-1,t-1,ar,dp)});
	return dp[i][t] = ans;
}
void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n,0);
	for(auto & i : ar)
	cin >> i;
	sort(ar.begin(),ar.end());
	vector<vector<ll>> dp(n,vector<ll>(301,-1));
	ll ans = unp(n-1,300,ar,dp);
	cout << ans << "\n"; 
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

