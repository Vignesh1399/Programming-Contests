#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(ll k){
	ll w,h,l,u,r,d;
	cin >> w >> h >> l >> u >> r >> d;
	vector<vector<double>> dp(h+1,vector<double>(w+1,0.0));
	for(ll i=1;i<=h;i++){
		for(ll j=1;j<=w;j++){
			if(i>=u && i<=d && j>=l && j<=r)
			dp[i][j] = 0.0;
			else if(i==1 && j==1)
			dp[i][j] = 1.0;
			else if(i==h && j==w)
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
			else if(i==h)
			dp[i][j] = 0.5*dp[i-1][j] + dp[i][j-1];
			else if(j==w)
			dp[i][j] = dp[i-1][j] + 0.5*dp[i][j-1];
			else
			dp[i][j] = 0.5 * (dp[i-1][j] + dp[i][j-1]);
		}
	}
	cout<<setprecision(10)<<fixed;
	cout<<"Case #"<<k<<": "<<dp[h][w]<<"\n";
}

int main() {
    FAST;
    ll t=1,k=1;
    cin>>t;
    while(t--) solve(k++);	
    return 0;
}

