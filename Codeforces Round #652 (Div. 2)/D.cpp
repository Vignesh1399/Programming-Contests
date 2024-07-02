#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll MOD = 1e9 + 7;
ll dp[2000001];
void pre(){
	for(ll i=3;i<=2e6;i++){
		dp[i] = ((dp[i-1] + (2*dp[i-2])%MOD)%MOD + (i%3==0))%MOD;
	}
}
void solve(){
	ll n;
	cin >> n;
	ll ans = (dp[n]*4)%MOD;
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    pre();
    cin>>t;
    while(t--) solve();	
    return 0;
}

