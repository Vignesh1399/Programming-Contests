#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m;
	ll ans = 0;
	cin >> n >> m;
	vector<vector<char>> ar(n+1,vector<char>(m+1,'z'));
	vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			cin >> ar[i][j];
		}
	}
	for(ll j=1;j<=m;j++){
		bool flag=0;
		for(ll i=1;i<=n;i++){
			if(i == 1)
			continue;
			else if(ar[i][j] > ar[i-1][j])
			dp[i][j] = 1;
			else if(ar[i][j] == ar[i-1][j])
			dp[i][j] = dp[i][j-1];
			else{
				dp[i][j] = dp[i][j-1];
				if(!dp[i][j])
				flag=1;
			}
		}
		if(flag){
			//cout<<j<<" ";
			for(ll i=1;i<=n;i++)
			dp[i][j] = dp[i][j-1];
			++ans;
		}
	}
	cout<<ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

