#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll dp[500001][8];
bool ok2[4][4];
bool ok3[8][8];

void init2(){
	for(ll i=0;i<4;i++){
		for(ll j=0;j<4;j++){
			ll a = (i>>0) & 1;
			ll b = (j>>0) & 1;
			ll c = (j>>1) & 1;
			ll d = (i>>1) & 1;
			if((a+b+c+d)%2)
			ok2[i][j] = 1;
		}
	}
}
void init3(){
	for(ll i=0;i<8;i++){
		for(ll j=0;j<8;j++){
			ll temp1 = 0;
			for(ll k=0;k<2;k++){
				temp1 += (i>>k) & 1;
				temp1 += (j>>k) & 1;
			}
			ll temp2 = 0;
			for(ll k=1;k<3;k++){
				temp2 += (i>>k) & 1;
				temp2 += (j>>k) & 1;
			}
			if(temp1%2 && temp2%2)
			ok3[i][j] = 1;
		}
	}
}
ll findmin3(ll col, ll msk, vector<vector<bool>> &ar){
	if(col<0)
	return 0;
	if(dp[col][msk] != -1)
	return dp[col][msk];
	ll ans = 1e9;
	ll gridmsk = ar[0][col]*1ll + ar[1][col]*2ll + ar[2][col]*4ll;
	for(ll prev=0;prev<8;prev++){
		if(ok3[prev][msk])
		ans = min(ans,findmin3(col-1,prev,ar));
	}
	ans += __builtin_popcount(gridmsk ^ msk);
	dp[col][msk] = ans;
	return ans;
}
ll findmin2(ll col, ll msk, vector<vector<bool>> &ar){
	if(col<0)
	return 0;
	if(dp[col][msk] != -1)
	return dp[col][msk];
	ll ans = 1e9;
	ll gridmsk = ar[0][col]*1ll + ar[1][col]*2ll;
	for(ll prev=0;prev<4;prev++){
		if(ok2[prev][msk])
		ans = min(ans,findmin2(col-1,prev,ar));
	}
	ans += __builtin_popcount(gridmsk ^ msk);
	dp[col][msk] = ans;
	return ans;
}
void solve(){
	ll n,m;
	memset(dp,-1,sizeof(dp));
	cin >> n >> m;
	string s[n];
	vector<vector<bool>> ar(n,vector<bool>(m,0));
	for(ll i=0;i<n;i++)
	cin >> s[i];
	if(n>=4){
		cout << -1 ;
		return ;
	}
	if(n==1){
		cout << 0 ;
		return ;
	}
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++)
		ar[i][j] = s[i][j] - '0';
	}
	ll ans = 1e9;
	if(n==2){
		init2();
		for(ll i=0;i<4;i++){
			ans = min(ans,findmin2(m-1,i,ar));
		}
	}
	else{
		init3();
		for(ll i=0;i<8;i++){
			ans = min(ans,findmin3(m-1,i,ar));
		}
	}
	cout << ans ;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

