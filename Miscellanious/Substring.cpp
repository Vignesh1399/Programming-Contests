#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll dp[300001][26];
ll rec[300001];

void dfs(ll s, vector<ll> g[], string &st){
	//cout << s << "\n";
	if(rec[s] != -1)
	return ;
	rec[s] = 1;
	dp[s][st[s] - 'a'] = 1;
	for(ll j=0;j<26;j++)
	dp[s][j] = max(0ll,dp[s][j]);
	for(auto i : g[s]){
		if(rec[i] == 1){
			cout << -1;
			exit(0);
		}
		dfs(i,g,st);
	}
	rec[s] = 0;
	for(ll j=0;j<26;j++){
		ll temp = 0;
		for(auto i : g[s])
		temp = max(temp,dp[i][j]);
		dp[s][j] += temp;
		//cout << s << " " << j << " " << dp[s][j] << "\n";
	}
}

void solve(){
	memset(dp,-1,sizeof(dp));
	memset(rec,-1,sizeof(rec));
	ll n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	s = s[0] + s;
	//cout << s[5] << "\n";
	vector<ll> g[n+1];
	for(ll i=0;i<m;i++){
		ll x,y;
		cin >> x >> y;
		g[x].pb(y);
	}
	for(ll i=1;i<=n;i++){
		if(rec[i] == -1)
		dfs(i,g,s);
	}
	ll ans = 0;
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<26;j++)
		ans = max(ans,dp[i][j]);
	}
	cout << ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

