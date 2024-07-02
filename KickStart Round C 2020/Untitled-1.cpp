#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,k;
	string s;
	cin >> n >> k;
	cin >> s;
	s = s[0]+s;
	vector<ll> pr(n+1,0), dp(n+1,0);
	for(ll i=1;s[i];i++){
		if(s[i] == '0')
		pr[i] = pr[i-1];
		else
		pr[i] = pr[i-1] + 1;
	}
	for(ll i=1;s[i];i++){
		if(s[i] == '0')
		dp[i] = min(pr[i], 1 + pr[max(i-1,0ll)] - pr[max(i-k,0ll)] + dp[max(i-k,0ll)]);
		else
		dp[i] = min(pr[i], pr[max(i-1,0ll)] - pr[max(i-k,0ll)] + dp[max(i-k,0ll)]);
		cout<<dp[i]<<' ';
	}
	ll ans = dp[n];
	for(ll i=n;i>n-k;i--)
	ans = min(ans,dp[n]);
	cout<<ans<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

