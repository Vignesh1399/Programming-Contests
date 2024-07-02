#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

vector<vector<ll>> dp(2e5+1,vector<ll>(2,-2));

ll dfs(ll s, ll d, vector<ll> &ar, ll n){
	if(s<=0 || s>n)
	return 0ll;
	else if(dp[s][d] != -2)
	return dp[s][d];
	else{
		dp[s][d] = -1;
		if(!d)
		dp[s][d] = dfs(s-ar[s], !d, ar, n);
		else
		dp[s][d] = dfs(s+ar[s], !d, ar, n);
		if(dp[s][d] != -1)
		dp[s][d] += ar[s];
		return dp[s][d];
	}
}

void solve(){
	ll n;
	dp[1][0] = dp[1][1] = -1;
	cin >> n;
	vector<ll> ar(n+1,0);
	for(ll i=2;i<=n;i++){
		cin >> ar[i];
	}
	for(ll i=2;i<=n;i++){
		if(dp[i][0] == -2ll)
		dfs(i,0,ar,n);
	}
	for(ll i=2;i<=n;i++){
	if(dp[i][0] == -1)
	cout<<-1<<"\n";
	else
	cout<<dp[i][0] + i - 1<<"\n";
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

