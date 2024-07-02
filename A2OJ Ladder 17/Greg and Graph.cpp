#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

/*
There 2 kinfd of intersections
1.
horizontal - vertical
2.
vertical - horizontal
H - H , V - V can never occur as it will lead to >1 meeting points   
Idea: 
Calculate distance from start -  just before meeting point
	+
just after meeting point  - goal 
for both lahub and lahubina
Implementation
dp1[i][j]: max workout starting from 1,1 to i,j ( going right/down)
dp2[i][j]: max workout starting from n,m to i,j (up/left)
dp3[i][j]: max workout starting from n,1 to i,j	(right/up)
dp4[i][j]: max workout starting from 1,m to i,j (left/down)

*/

void solve(){
	ll n,m,ans = 0;
	cin >> n >> m;
	vector<vector<ll>> ar(n+2,vector<ll>(m+2,0)), dp1(n+2,vector<ll>(m+2,0)), dp2(n+2,vector<ll>(m+2,0)), dp3(n+2,vector<ll>(m+2,0)), dp4(n+2,vector<ll>(m+2,0));
	for(ll i=1;i<=n;i++)
	for(ll j=1;j<=m;j++)
	cin >> ar[i][j];
	
	for(ll i=1;i<=n;i++)
	for(ll j=1;j<=m;j++)
	dp1[i][j] = max(dp1[i][j-1],dp1[i-1][j]) + ar[i][j];
	
	for(ll i=n;i>=1;i--)
	for(ll j=m;j>=1;j--)
	dp2[i][j] = max(dp2[i+1][j], dp2[i][j+1]) + ar[i][j];
	
	for(ll i=n;i>=1;i--)
	for(ll j=1;j<=m;j++)
	dp3[i][j] = max(dp3[i][j-1], dp3[i+1][j]) + ar[i][j];
	
	for(ll i=1;i<=n;i++)
	for(ll j=m;j>=1;j--)
	dp4[i][j] = max(dp4[i-1][j], dp4[i][j+1]) + ar[i][j];
	
	for(ll i=2;i<n;i++)
	for(ll j=2;j<m;j++)
	ans = max({ans, dp1[i][j-1] + dp2[i][j+1] + dp3[i+1][j] + dp4[i-1][j], dp1[i-1][j] + dp2[i+1][j] + dp3[i][j-1] + dp4[i][j+1]});
	
	cout<<ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

