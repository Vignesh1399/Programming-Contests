#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n+1,0);
	vector<vector<ll>> dp(n+1,vector<ll>(2,0));
	dp[0][1] = -1e18;
	string s;
	for(ll i=0;i<n;i++)
	cin >> ar[i+1];
	cin >> s;
	s = s[0] + s;
	reverse(s.begin()+1,s.end());
	reverse(ar.begin()+1,ar.end());
	for(ll i=1;s[i];i++){
		if(s[i] == '1'){
			dp[i][0] = dp[i-1][0] + ar[i];
			dp[i][1] = max(dp[i-1][0], dp[i-1][1] + ar[i]);
		}
		else{
			dp[i][0] = dp[i-1][0];
			dp[i][1] = dp[i-1][1] + ar[i];
		}
	}
	ll ans = max(dp[n][0],dp[n][1]);
	cout<<ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

