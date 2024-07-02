#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll count(string &s,ll i, ll j,vector<vector<ll>> &dp){
	if(i==j)
	return 1;
	else if(i+1 == j)
	return 2 + (s[i] == s[j]);
	else if(dp[i][j] != -1)
	return dp[i][j];
	dp[i][j] = 0;
	if(s[i] == s[j])
	dp[i][j] += 1 + count(s,i+1,j-1,dp);
	dp[i][j] += count(s,i,j-1,dp);
	dp[i][j] += count(s,i+1,j,dp);
	dp[i][j] -= count(s,i+1,j-1,dp);
	//cout<<i <<" "<<j<<" "<<dp[i][j]<<"\n";
	return dp[i][j]; 
}

void solve(){
	string s;
	cin >> s;
	//count(s,i,j) : Denotes the number of Palindromic strings of length atleast 1
	//that can be formed by deleting some characters from deleting some characters
	//from [i,j] inclusive
	vector<vector<ll>> dp(61,vector<ll>(61,-1));
	ll ans = count(s,0,sz(s)-1,dp);
	cout<<ans;
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

