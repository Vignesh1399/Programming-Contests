#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll tc = 0;
void solve(){
	ll n;
	cin >> n;
	string in,out;
	cin >> in >> out;
	vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
	for(ll i=0;i<n;i++){
		for(ll j=i;j<n;j++){
			if(i == j){
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i][j-1] && (out[j-1] == 'Y');
			if(in[j]=='N')
			dp[i][j] = 0;
		}
	}
	for(ll i=n-1;i>=0;i--){
		for(ll j=i-1;j>=0;j--){
			dp[i][j] = dp[i][j+1] && (out[j+1] == 'Y');
			if(in[j] == 'N')
			dp[i][j] = 0;
		}
	}
	cout << "Case #" << ++tc << ":\n";
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			if(dp[i][j])
			cout << "Y";
			else
			cout << "N";
		}
		cout << "\n";
	}
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

