#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll cs = 0;
bool ok(ll n){
	ll lb = 0, ub = 1e5;
	while(lb<=ub){
		ll mid = (lb+ub)/2;
		if(mid*mid == n)
		return 1;
		else if(mid*mid<n)
		lb = mid+1;
		else
		ub = mid-1;
	} 
	return 0;
}
void solve(){
	ll n,ans=0;
	cin >> n;
	vector<ll> ar(n+1,0);
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
	}
	vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			dp[i][j] = dp[i][j-1]+ ar[j];
			if(ok(dp[i][j]))
			ans++;
		}
	}
	cout<<"Case #"<<++cs<<": "<<ans<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

