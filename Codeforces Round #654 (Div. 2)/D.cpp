#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,k;
	cin >> n >> k;
	ll tk = k;
	vector<vector<bool>> ar(n+1,vector<bool>(n+1,0));
	for(ll j=0;j<n && k;j++){
		ll tj = j;
		for(ll i=0;i<n && k;i++){
			ar[i][tj] = 1;
			--k;
			++tj;
			tj%=n;
		}
	}
	ll maxr = 0,minr=1e9,maxc=0,minc=1e9;
	for(ll i=0;i<n;i++){
		ll tsum = 0;
		for(ll j=0;j<n;j++){
			tsum += ar[i][j];
		}
		maxr = max(maxr,tsum);
		minr = min(minr,tsum);
	}
	for(ll j=0;j<n;j++){
		ll tsum = 0;
		for(ll i=0;i<n;i++){
			tsum += ar[i][j];
		}
		maxc = max(maxc,tsum);
		minc = min(minc,tsum);
	}
	ll ans = (maxr-minr)*(maxr-minr) + (maxc-minc)*(maxc-minc);
	cout << ans << '\n';
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++)
		cout << ar[i][j];
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

