#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m;
	cin >> n >> m ;
	vector<vector<bool>> dp1(n+1,vector<bool>(m+1,0)),dp2(n+2,vector<bool>(m+2,0));
	vector<vector<char>> ar(n+1,vector<char>(m+1,'0'));
	vector<int> dis(n+m+1,0);
	for(ll i=1;i<=n;i++)
	for(ll j=1;j<=m;j++)
	cin >> ar[i][j];
	ll ans = 2;
	multiset<ll> ms;
	dp1[1][1] = 1;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(ar[i][j] == '#') continue;
			dp1[i][j] = dp1[i][j] | dp1[i][j-1] | dp1[i-1][j];
		}
	}
	dp2[n][m] = 1;
	for(ll i=n;i>=1;i--){
		for(ll j=m;j>=1;j--){
			if(ar[i][j] == '#') continue;
			dp2[i][j] = dp2[i][j] | dp2[i][j+1] | dp2[i+1][j];
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if((i==1 && j==1) || (i==n && j==m)) continue;
			if(dp1[i][j] && dp2[i][j])
			dis[i+j]++;
		}
	}
	for(ll i=2;i<=n+m;i++){
		if(dis[i] == 1)
		ans = 1;
	}
	if(!dp1[n][m])
	ans = 0;
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

