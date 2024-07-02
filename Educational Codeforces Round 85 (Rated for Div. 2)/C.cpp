#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >>n;
	vector<ll> ar(n+1,0),br(n+1,0),dp(n+1,0);
	for(ll i=1;i<=n;i++)
	cin>>ar[i]>>br[i];
	for(ll i=1;i<=n;i++){
		if(i==1)
		dp[i] = max(0ll,ar[i] - br[n]);
		else{
			dp[i] = dp[i-1] + max(ar[i]  - br[i-1],0ll);
		}
		//cout<<dp[i]<<" ";
	}
	ll ans = 1e18;
	for(ll i=1;i<=n;i++){
		if(i==1)
		ans = min(ans,dp[n] - dp[i] + ar[i]);
		else 
		ans = min(ans,dp[n] - dp[i] + dp[i-1] + ar[i]);
		/*
		else 
		ans = min(ans,ar[i]+dp[n-1]-br[n]);
		*/
	}
	cout<<ans;
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

