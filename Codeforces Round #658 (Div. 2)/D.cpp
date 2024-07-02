#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll subsetsum(ll idx, ll sum, vector<ll> &len, vector<vector<ll>> &dp){
	if(sum==0)
	return 1;
	else if(idx<0)
	return 0;
	if(dp[idx][sum] != -1)
	return dp[idx][sum];
	dp[idx][sum] = subsetsum(idx-1,sum,len,dp);
	if(sum>=len[idx])
	dp[idx][sum] = dp[idx][sum] | subsetsum(idx-1,sum-len[idx],len,dp);
	return dp[idx][sum];
}

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(2*n);
	vector<vector<ll>> dp(2*n+1,vector<ll> (2*n+1,-1));
	for(auto &i : ar)
	cin >> i;
	vector<ll> len;
	ll sum=0;
	set<ll,greater<ll>> s;
	for(ll i=1;i<=2*n;i++)
	s.insert(i);
	for(ll i=2*n-1;i>=0;i--){
		if(ar[i] == *s.begin()){
			len.pb(2*n - i - sum);
			sum += len.back();
		}
		s.erase(ar[i]);
	}
	subsetsum(sz(len)-1,n,len,dp);
	if(dp[sz(len)-1][n] == 1)
	cout << "YES\n";
	else
	cout <<"NO\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

