#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll ar[3],ma=0;
	for(ll i=0;i<3;i++) cin >> ar[i];
	pair<ll,ll> p;
	for(ll i=0;i<3;i++){
		ma = max(ar[i],ma);
	}
	for(ll i=0;i<3;i++){
		for(ll j=i+1;j<3;j++){
			if(ar[i] == ar[j] && ar[i] == ma)
			p = {i,j};
		}
	}
	sort(ar,ar+3,greater<ll>());
	if(ar[0] == ar[1]){
		cout << "YES\n";
		cout << ar[2] << " " << ar[0] << " " << ar[2];
	}
	else
	cout << "NO";
	cout << "\n";	
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

