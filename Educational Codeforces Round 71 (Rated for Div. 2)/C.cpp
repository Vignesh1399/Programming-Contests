#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
//pipe, pillar
ll cost(ll i, ll h, string &s, ll a, ll b,vector<vector<ll>> &dp){
	if(i == -1)
	return h*b;
	if(dp[i][h] != -1)
	return dp[i][h];
	if(s[i] == '1' && h == 1)
	return dp[i][h] = 1e15;
	ll ans = 0;
	ll x1=1e15,x2=1e15;
	if(i == 0){
		if(h == 1)
		x1 = cost(i-1,1,s,a,b,dp) + b*h + a;
		else
		x1 = cost(i-1,1,s,a,b,dp) + 2*(a+b);
		return dp[i][h] = x1;
	}
	x1 = cost(i-1,h,s,a,b,dp) + b*h + a;
	if(s[i] != '1')
	x2 = cost(i-1,3-h,s,a,b,dp) + 2*a + b*h;
	ans = min(x1,x2);
	return dp[i][h] = ans;
}
void solve(){
	ll n,a,b;
	cin >> n >> a >> b;
	vector<vector<ll>> dp(n+1,vector<ll>(3,-1));
	string s;
	cin >> s;
	ll ans = cost(n-1,1,s,a,b,dp);
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

