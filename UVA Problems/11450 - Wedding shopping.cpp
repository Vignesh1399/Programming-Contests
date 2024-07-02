#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll dp[200][200];

bool shop(ll i, ll mon, vector<vector<ll>> &p){
	if(i==-1)
	return mon==0;
	if(dp[i][mon] != -1)
	return dp[i][mon];
	bool pos = 0;
	for(auto j : p[i]){
		if(mon-j>=0)
		pos = pos || shop(i-1,mon-j,p);
	}
	return (dp[i][mon] = pos);
}
void solve(){
	memset(dp,-1,sizeof(dp));
	ll m,c;
	//m-budget, c - no of garments
	cin >> m >> c;
	vector<vector<ll>> price;
	for(ll i=0;i<c;i++){
		price.pb(vector<ll>());
		ll k;
		cin >> k;
		for(ll j=0;j<k;j++){
			ll x;
			cin >> x;
			price[i].pb(x);
		}
	}
	for(ll i=m;i>=1;i--)
	shop(c-1,i,price);
	ll ans = -1;
	for(ll i=1;i<=m;i++){
		if(dp[c-1][i] > 0)
		ans = i;
	}
	if(ans == -1)
	cout << "no solution\n";
	else
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

