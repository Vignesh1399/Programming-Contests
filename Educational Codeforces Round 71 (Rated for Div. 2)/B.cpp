#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll di[] = {0,0,-1,1};
ll dj[] = {-1,1,0,0}; 
bool within(ll i, ll j, ll n, ll m){
	return (i>=1 && i<=n && j>=1 && j<=m);
}
void solve(){
	ll n,m;
	cin >> n >> m;
	vector<vector<ll>> ar(n+1,vector<ll>(m+1,0)),br(n+1,vector<ll>(m+1,0));
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			cin >> ar[i][j];
		}
	}
	vector<pair<ll,ll>> ans;
	for(ll i=1;i<=n-1;i++){
		for(ll j=1;j<=m-1;j++){
			ll flag = 0;
			flag = ar[i][j] + ar[i+1][j] + ar[i][j+1] + ar[i+1][j+1];
			if(flag == 4)
			ans.eb(i,j);
		}
	}
	for(auto i : ans){
		auto x = i.first, y = i.second;
		br[x][y] = br[x+1][y] = br[x+1][y+1] = br[x][y+1] = 1;
	}
	bool flag = 1;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(ar[i][j] != br[i][j])
			flag = 0;
		}
	}
	if(!flag){
		cout << -1 ;
		return ;
	}
	cout << sz(ans) << "\n";
	for(auto i : ans)
	cout << i.first << " " << i.second << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

