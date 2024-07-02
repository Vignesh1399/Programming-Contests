#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

vector<vector<ll>> dp(31,vector<ll>(31,1));
void findncr(){
	for(ll i=2;i<=30;i++){
		for(ll j=1;j<i;j++)
		dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
	}
}

void solve(){
	findncr();
	ll m,n,t,ans=0;
	cin >> n >> m >> t;
	for(ll i=4;i<t;i++){
		if(n>=i && m>=t-i)
		ans += dp[n][i] * dp[m][t-i];
	}
	cout<<ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

