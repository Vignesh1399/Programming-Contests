#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> cost(n+1,0);
	vector<vector<ll>> dp(n+1,vector<ll>(2,-1));
	// 0 : normal, 1 : reverse
	dp[0][0] = dp[0][1] = 0;
	string s[n+1];
	s[0] = "a";
	for(ll i=1;i<=n;i++)
	cin >> cost[i];
	for(ll i=1;i<=n;i++)
	cin >> s[i];
	for(ll i=1;i<=n;i++){
		dp[i][0] = dp[i][1] = 1e18;
		reverse(s[i].begin(),s[i].end());
		reverse(s[i-1].begin(),s[i-1].end());
		string prev = s[i-1];
		string rev = s[i];
		reverse(s[i].begin(),s[i].end());
		reverse(s[i-1].begin(),s[i-1].end());
		if(s[i].compare(s[i-1])>=0 && dp[i-1][0] != -1)
			dp[i][0] = min(dp[i][0],dp[i-1][0]);
		if(s[i].compare(prev)>=0 && dp[i-1][1] != -1)
			dp[i][0] = min(dp[i][0],dp[i-1][1]);
		if(rev.compare(s[i-1])>=0 && dp[i-1][0] != -1)
			dp[i][1] = min(dp[i][1],dp[i-1][0] + cost[i]);
		if(rev.compare(prev)>=0 && dp[i-1][1] != -1)
			dp[i][1] = min(dp[i][1],dp[i-1][1] + cost[i]);
		if(dp[i][0] == 1e18)
		dp[i][0] = -1;
		if(dp[i][1] == 1e18)
		dp[i][1] = -1;
	}
	if(dp[n][1] == dp[n][0] && dp[n][0] == -1)
	cout<<-1;
	else if(dp[n][1] !=-1 && dp[n][0] != -1)
	cout<<min(dp[n][1],dp[n][0]);
	else
	cout<<max(dp[n][0],dp[n][1]);
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

