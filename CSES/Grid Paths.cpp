#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll MOD = 1e9 + 7;

void solve(){
	ll n;
	cin >> n;
	vector<vector<char>> ar(n+1,vector<char>(n+1,'0'));
	vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			cin >> ar[i][j];	
			if(i == 1 && j == 1) 
				dp[i][j] = 1;
			else
				dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
			if(ar[i][j] == '*')
				dp[i][j] = 0;
		}
	}
	cout << dp[n][n];
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

