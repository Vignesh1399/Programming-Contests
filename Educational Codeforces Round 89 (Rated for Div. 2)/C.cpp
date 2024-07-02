#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;


void solve(){
	ll n,m;
	cin >> n >> m;
	ll ar[50][50];
	for(ll i=1;i<=n;i++)
	for(ll j=1;j<=m;j++)
	cin >> ar[i][j];
	ll ans = 0;
	for(ll top=2,bottom=n+m;top<bottom;top++,bottom--){
		ll z,o;
		z = o = 0;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				if(i+j == top || i+j == bottom){
					o += (ar[i][j])&1;
					z += !(ar[i][j]&1);
				}
			}
		}
		ans += min(o,z);
	}
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

