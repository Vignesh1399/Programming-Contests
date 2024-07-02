#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	ll n,W;
	cin>>n>>W;
	vector<ll> w(n+1),v(n+1);
	ll dp[n+1][W+1];
	/*
	State
	dp[i][j]: Denotes the maximum value of items(from 1 to i) picked in the bag having total weight ==j
	Recurrence
	2 choices 1: we pick the ith element, 2: we dont pick the ith element 
	The 2 choices are checked for all weights
	dp[i][j]=maximum(value of items picked from 1 to i-1 with weight <=j,value of items picked from 1 to i-1 with weight ==(j-weight[i]) + value[i])
	*/
	for(ll i=1;i<=n;i++)
	cin>>w[i]>>v[i];
	for(ll i=0;i<=n;i++){
		dp[i][0]=0;
	}
	ll ans=0;
	for(ll i=0;i<=W;i++)
		dp[0][i]=0;
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<=W;j++){
			if(w[i]>j)
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
