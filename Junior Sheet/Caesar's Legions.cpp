#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll MOD = 1e8;
ll dp[101][101][11][11];
ll k1,k2;

ll find_arr(ll n1, ll n2, ll x1, ll x2){
	if(n1<0 || n2<0)
	return 0;
	if(n1 + n2 == 0){
		dp[n1][n2][x1%k1][x2%k2] = 1;
		return 1;
	}
	if(dp[n1][n2][x1][x2] != -1)
	return dp[n1][n2][x1][x2];
	
	ll ans = 0;
	if(x1 == k1){
		ans = find_arr(n1,n2-1,0,1) % MOD;
	}
	else if(x2 == k2){
		ans = find_arr(n1-1,n2,1,0) % MOD;
	}
	else{
		
		ans = (ans + find_arr(n1,n2-1,0,x2+1)) % MOD;
		ans = (ans + find_arr(n1-1,n2,x1+1,0)) % MOD;
	}
	dp[n1][n2][x1][x2] = ans;
	//cout << n1 <<" " << n2 <<" "<< x1 <<" "<< x2 <<" "<< ans<< "\n";
	return ans;
}

void solve(){
	ll n1,n2;
	cin >> n1 >> n2 >> k1 >> k2;
	memset(dp,-1,sizeof(dp));
	find_arr(n1,n2,0,0);
	ll ans = dp[n1][n2][0][0];
	cout << ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

