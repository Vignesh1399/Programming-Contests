#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void dfs(vector<ll> g[], ll s, vector<ll> &ar, vector<ll> &dp, vector<ll> &cnt, vector<ll> &sum){
	sum[s] = ar[s];
	if(!sz(g[s]))
	cnt[s] = 1;
	for(auto i : g[s]){
		dfs(g,i,ar,dp,cnt,sum);
		cnt[s] += cnt[i];
		sum[s] += sum[i];
		dp[s] = max(dp[s],dp[i]);
	}
	dp[s] = max(dp[s],sum[s]/cnt[s] + ((sum[s]%cnt[s])>0));
	//cout << s << " " << dp[s] << "\n";
}
void solve(){
	ll n;
	cin >> n;
	vector<ll> g[n+1];
	vector<ll> ar(n+1,0);
	for(ll i=1;i<=n-1;i++){
		ll p;
		cin >> p;
		g[p].eb(i+1);
	}
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	vector<ll> dp(n+1,0);
	vector<ll> cnt(n+1,0);
	vector<ll> sum(n+1,0);
	dfs(g,1,ar,dp,cnt,sum);
	cout << dp[1] << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

