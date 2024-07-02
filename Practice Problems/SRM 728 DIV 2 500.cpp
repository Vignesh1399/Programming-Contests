#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(a) signed(a.size())
using namespace std;

class IncreasingSequencesEasy{
public:
int count(vector<int> L, vector<int> R){
	ll n = sz(L);
	ll MOD = 998244353;
	vector<vector<int>> dp(n+1,vector<int>(1e4+1,0));
	for(ll i=0;i<=1e4;i++)
	dp[0][i] = 1;
	for(ll i=1;i<=n;i++){
		for(ll x = L[i-1]; x<=R[i-1]; x++){
			dp[i][x] = (dp[i][x] + dp[i-1][x-1])%MOD;
			//if(i == 1)
			//cout << dp[i][x] << " ";
		}
		for(ll j=1;j<=1e4;j++)
			dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
	}
	int ans = dp[n][10000];
	return ans;
}
};