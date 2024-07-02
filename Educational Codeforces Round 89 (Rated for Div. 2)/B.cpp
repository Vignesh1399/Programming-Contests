#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,x,m;
	cin >> n >> x >> m;
	ll cmin,cmax;
	cmin = cmax = x;
	for(ll i=1;i<=m;i++){
		ll l,r;
		cin >> l >> r;
		if(l>cmax || r<cmin){
			
		}
		else{
			cmin = min(l,cmin);
			cmax = max(r,cmax);
		}
	}
	cout << cmax - cmin + 1;
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

