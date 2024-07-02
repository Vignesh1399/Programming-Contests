#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll find_subarray(vector<ll> &ar, vector<ll> &dp, ll i){
	if(i == 0)
	return i;
	else if(dp[i] != -1)
	return dp[i];
	ll prev = find_subarray(ar,dp,i-1);
	if(ar[i] >= ar[i-1])
	dp[i] = 1 + prev;
	else
	dp[i] = 1;
	return dp[i];
}

void solve(){
	/*
	Solve(n): Nummber of non decresing subarrays ending at n
	Therefore 
	assuming we know about solve(i-1)
	solve(i) = (ar[i] >= ar[i-1]) ? 1 + solve(i-1) : 1;
	base case solve(0) = 0;
	*/
	ll n;
	cin >> n;
	vector<ll> ar(n+1,0),dp(n+1,-1);
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	find_subarray(ar,dp,n);
	ll ans = 0;
	for(ll i=1;i<=n;i++)
	ans += dp[i];
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

