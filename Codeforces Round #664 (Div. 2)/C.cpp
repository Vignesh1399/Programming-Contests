#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m;
	cin >> n >> m;
	vector<ll> ar(n+1),br(m+1);
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	for(ll j=1;j<=m;j++)
	cin >> br[j];
	vector<vector<int>> val(n+1,vector<int>(1<<10,0));
	for(ll j=1;j<=m;j++){
		val[1][ar[1]&br[j]]++;
	}
	for(ll i=2;i<=n;i++){
		for(ll j=0;j<(1ll<<10);j++){
			for(ll k=1;k<=m;k++){
				if(val[i-1][j])
				val[i][j|(ar[i]&br[k])]++;
			}
		}
	}
	ll ans = 1e10;  
	for(ll i=0;i<(1ll<<10);i++){
		if(val[n][i]){
			ans=i;
			break;
		}
	}
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

