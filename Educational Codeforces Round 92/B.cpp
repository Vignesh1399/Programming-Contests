#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll dp[100001][6][2];
vector<ll> ar;
ll findMScore(ll idx, ll left, ll lastl, ll moves){
	if(moves == 0)
	return ar[idx];
	if(dp[idx][left][lastl] != -1)
	return dp[idx][left][lastl];
	ll ans = 0;
	if(!lastl && idx>1 && left)
	ans = max(ans,ar[idx]+findMScore(idx-1,left-1,1,moves-1));
	ans = max(ans,ar[idx]+findMScore(idx+1,left,0,moves-1));
	dp[idx][left][lastl] = ans;
	return ans;
}
void solve(){
	ll n,k,z;
	cin >> n >> k >> z;
	ar.resize(n+1,0);
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
	}
	for(ll i=0;i<=n;i++){
		for(ll j=0;j<=z;j++){
			dp[i][j][0] = dp[i][j][1] = -1;
		}
	}
	ll ans = findMScore(1,z,0,k);
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

